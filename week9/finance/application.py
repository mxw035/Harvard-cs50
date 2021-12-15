import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    '''this works need to make loop'''


    index = db.execute("SELECT * FROM stocks WHERE user = ?", session["user_id"])
    users = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
    cash = users[0]["cash"]
    name = users[0]["username"]
    bcash = users[0]["bcash"]
    scash = users[0]["scash"]
    total = bcash - scash
    grand = cash + total

    return render_template("index.html", index = index, cash = cash, name = name, total = total, grand = grand, bcash = bcash, scash = scash)



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock gets post method"""
    if request.method=="POST":
        '''Uses the look up fxn to check stock on stats '''
        symbol = request.form.get("symbol")
        quote = lookup(symbol)
        shares = request.form.get("shares")

        if not symbol:
            return apology("a valid symbol must be provide", 400)
        elif not shares:
            #flash('invail shares')
            return apology("please enter vaild shares", 400)
        try:
            shares = int(shares)
            if shares < 1:
                return apology("Please enter postive number", 400)
        except ValueError:
            return apology("share must be a positive integer", 400)

        else:

            name = quote["name"]
            symbol = quote["symbol"]
            price = quote["price"]
            '''Gets value of stock base on symbol price and shares to be bought '''
            value = int(shares) * float(price)

            ''' Updates cash based on buy '''
            cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
            if cash < value:
                return apology("Not enough funds", 400)
            else:
                cash = cash - value
                users = db.execute("SELECT * FROM users WHERE id = ? ", session["user_id"])
                bcash = users[0]["bcash"]
                bcash = bcash + value
                db.execute("UPDATE users SET bcash = ? WHERE id = ?", bcash, session["user_id"])
                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])
                flash("Stock Bought")
                ''' inserts infor into stocks for purchased stock'''
                db.execute("INSERT INTO stocks (user, name, symbol, price, value, action, bought, shares) VALUES( ?, ?, ?, ?, ?, ?, ?, ?)", session["user_id"], name, symbol, price, value, "buy", shares, shares)

        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute("SELECT * FROM stocks WHERE user = ? ORDER BY symbol", session["user_id"])

    return render_template("history.html", history = history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method=="POST":
        symbol = request.form.get("symbol")

        if symbol is None:
            return apoplgy("Please enter symbol", 400)

        else:
            quote = lookup(symbol)

            if not quote:
                return apology("Not a valid symbol", 400)

            else:
                name = quote["name"]
                symbol = quote["symbol"]
                price = quote["price"]

        return render_template("quoted.html", name = name, symbol = symbol, price = price)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method=="POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        if not username:
            return apology("Must provide username", 400)
        elif len(rows) != 0:
            return apology("Username already taken", 400)
        elif not password:
            return apology("Must provide password", 400)
        elif not password == confirmation:
            return apology("Passwords must match", 400)
        else:
            code = generate_password_hash(password, method='pbkdf2:sha256', salt_length=8)

            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, code)

        return redirect('/')

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method=="POST":
        ''' gets shares and symbol info for stocks to to sell '''
        shares = request.form.get("shares")
        symbol = request.form.get("symbol")
        try:
            shares = int(shares)
            if shares < 1:
                return apology("Please enter postive number", 400)
        except ValueError:
            return apology("share must be a positive integer", 400)

        ''' uses the quote fxn to get current data on stock'''
        quote = lookup(symbol)
        name = quote["name"]
        symbol = quote["symbol"]
        price = quote["price"]


        check = db.execute("SELECT bought FROM stocks WHERE symbol = ? AND user = ? AND action = ?", symbol, session["user_id"], "buy")
        for i in range(len(check)):
            bcheck = (check[i])
            for x in bcheck:
                bc = (bcheck[x])
                if bc < shares:
                    flash("NO ENOUGH SHARES TO SELL")
                    return apology("Not enoguh shares", 400)

                if bc > int(shares):
                    amount = int(shares) * float(price)
                    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
                    cash = cash + float(amount)
                    users = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
                    scash = users[0]["scash"]
                    scash = scash + amount
                    shares = - int(shares)
                    db.execute("UPDATE users SET cash = ?, scash = ? WHERE id = ?", cash, scash, session["user_id"])
                    db.execute("INSERT INTO stocks (name, symbol, price, value, action, user, sold, shares) VALUES( ?, ?, ?, ?, ?, ?, ?, ?)", name, symbol, price, amount, "sell", session["user_id"], shares, shares)
                    flash("Sell Compelete")
                    return redirect('/')
                else:
                    flash("NOT ENOUGH SHARES")
                    return render("/sell.html")

    else:
        '''Works dont change '''
        data = db.execute("SELECT DISTINCT symbol FROM stocks WHERE user = ?", session["user_id"])
        return render_template("sell.html", data = data)




def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
