# VictoriaAlexander
## By Monica Evans 
### Flagstaff, AZ, UnitedStates 
### Video Link : https://youtu.be/XXzC7vhg1R4

#### Project Goal 

A few months ago I met with a local artist who was a family friend. She mentioned that she was wanting to set up a
website for her artwork where she could sell prints but she did not know how.
At the time I did not know how to begin to make a website. She knew I was taking classes in computer science and asked that when I
get to website development in my studies that I reach out.
I really enjoyed week 8 and 9 problem sets. It was these assignments that gave me the cofidence to chose Victoria's Art Show as my
final project.

#### How it all came together 

We had previously used bootstrap in class and I set out to learn more regaurding bootstrap on https://www.w3schools.com/bootstrap/bootstrap_ver.asp
It was there that I learned W3 had their own css framework. I had not specifically enjoyed using bootstrap and I didnt want to
use a template for my website lay out. Instead I wanted to design the layout my self.
I completed the tutorial on W3.css and began desining the website.
To start I completed a webpage demo to show to Victoria so that she might have an idea of what her page could look like.
This demo page was called Monica's Art which can be viewed here https://mxw035.github.io/Monica-s-Art/

##### Design 

My design:
- [x] Homepage
- [x] About the artist
- [x] Art Gallary
- [x] Inspiration behind the art: This idea was not possible because of the vast amount of art work that Victoria had and that she often does not remeber the 
 inspirations for her pieces.
- [x] Contact page
- [x] Next show
- [x] Ordering prints
- [x] Request custom art
- [x] Vicotira was really excited about also show caseing other local artists on the page as guests
- [x] Video page that would link to a youtube account where Victoria or Guests could film and share their process. 
- [x] requests for video topics

##### Files 

Because I was using Github pages for the website it needed to be a static webpage and all files would be in the same folder. There were 22 html files needed for the website. 70 jpg files that were Victoria's orginal work. 19jpg files for the guest artist section. As well as 12 other jpg files that were used throughout the webpage. 
There were more html files that orginally planned because along side creating her website Victoria also asked me to manage and help create products as well as helping to book public apperances. 
Most pages either started from the basic layout.html or slideshow.html. 
The files are as followed. 

###### Layout.html
A html page that has the basic layout for the site. Including NavBar 1 which has buttons linked to the home, about, art, contact, prints, videos and guest pages. And a second navbar with a button linked to the themes page. 
There is also a header "Victoria Alexander" that is also a button that will take the user back to the home page. 
###### slideshow.html 
Slideshow.html is very similar to layout.html with the addition of an h2 section for the name of the slideshow, as well as a div that contains the images and buttons used in the slideshow and a script section that makes the slideshow function. This page is used for displaying art work to the users. Orginally the slide show was automated but it was visually difficult and did not allow the user to look at each piece as long as they desired. 
###### index.html
https://mxw035.github.io/VictoriaAlexander/index.html
Index.html is the home page that uses layout.html. In addition there is a section including the artist name, location, photograph and a link to the contact page. As well as a automatic slideshow that will flip through all art work by Vicotria and when clicked will take the user to the Art.html page. 
###### about.html
https://mxw035.github.io/VictoriaAlexander/about.html
About.html is where the user can find out about Vicotira in addition to the layout.html features it also has 3 collums that include past artistic experience, a image of the artist and future plans. 
###### art.html
https://mxw035.github.io/VictoriaAlexander/art.html
Art.html is the basic slideshow page that flips through all 70 orginal pieces from Victoria. 
###### contact.html
https://mxw035.github.io/VictoriaAlexander/contact.html
Contact.html uses the basic layout page with the addition of two forms sections. One that allows users to reach out to Victoria with custom art request, custom card packs, and questions. The second one allows the user to subscribe to Victoria's email list to recieve updates. Orginally for form input I was going to use a sql database but since github is only for static sites I decieded to use FromSpree to store the user input data. FormSpree will also email us everytime a new submission is completed so that we can stay on top of users orders and requests. 
###### print.html
https://mxw035.github.io/VictoriaAlexander/prints.html
Print.html uses the basic layout page. List the purchase options and prices. Shows the index photos with names for all pieces. With links to the individual theme pages and card pack pages. As well as two form pages for poster print orders and card pack orders. There is also a link to contact page where custom art can be requested. 
###### video.html
https://mxw035.github.io/VictoriaAlexander/video.html
Video.html uses the layout page. With two additonal Forms added the email subscription form and the questions for Vicotria form. There is also a link to Vicotira's Youtube home page. Where the image of the Youtube page is there will be a video player since Victoria has not yet created a video it is blank at this time. 
###### guest.html
https://mxw035.github.io/VictoriaAlexander/guest.html
Guest.html uses the slideshow page. There are four collumns including the guest artist infromation(name, location, picture and email), a manual slideshow feautre the guest artist orginal work, a past experiences section and a future plans section. The goal of this page will be to help feature up and comming local artist trying to get into the artistic community. 
###### themes.html
https://mxw035.github.io/VictoriaAlexander/themes.html
Themes.html uses the layout page and contains the five art index images that link the user to the individual theme pages which include colors.html, linepeoples.html, lines.html, and natures.html. These pages can help users pic their favorite style and find the pieces name for ordering.
https://mxw035.github.io/VictoriaAlexander/lines.html
https://mxw035.github.io/VictoriaAlexander/colors.html
https://mxw035.github.io/VictoriaAlexander/linepeoples.html
https://mxw035.github.io/VictoriaAlexander/natures.html

###### Card Pages Include
color.html, linesone.html, linestwo.html, lpone.html, lptwo.html, lpthree.html, and nature.html
https://mxw035.github.io/VictoriaAlexander/linesone.html
https://mxw035.github.io/VictoriaAlexander/linestwo.html
https://mxw035.github.io/VictoriaAlexander/color.html
https://mxw035.github.io/VictoriaAlexander/nature.html
https://mxw035.github.io/VictoriaAlexander/lpone.html
https://mxw035.github.io/VictoriaAlexander/lptwo.html
https://mxw035.github.io/VictoriaAlexander/lpthree.html
###### stylesheet.css
Contians the basic code for the w3 yellow themed layout that is applied to all other pages. 
##### Debated Choices
- [x] payment
- [x] filter
- [x] template design
- [x] colors
###### Payment Options
In the begining Victoria had told me she would like to have a website where she could
sell prints but not the orginals. So I new we would need to have not only a way to print prints on demand but also to accept payments.
At this point I was not intrested in accepting payments on the website.

- [x] amazon merch
- [x] google merch
- [x] venmo
- [x] paypal
~~ - [x] square ~~
- [x] Etsy
Amazon and Google would both be good options for creating online store fronts where purchases could occur and be logged. I also mostly
use Amazon and Google for my printing need so I was familer with thier printing services and the quality of their prints.
I also liked that if we chose the Venmo route to start. Once payment was recieved Victoria could order the print from either Amazon or
Google and have it directly sent to the users home.
Paypal is the option for payment only that I believe would be best becuase it would allow us to have a button on the site that directly
lead the user to paypals secure payment process.
Unfortunately Square was not an option.
Venmo can also take payments for business but doesnot provided an onsite button. 
Eventually I am hoping to help Victoria set up a Paypal account and use their on site button to redirect users. 
###### Filter 
Orginally I had differnt options for every print including grayscale, sepia, and opacity. Each filter had three options min, normal and
max. This is a featur offered throught w3.css which I thoguht was cool. And some of paintings did look cool with the extra options.
However I decided that this altered the orginal art piece and cluttered up the website. I did keep the orginal layout for this feature
incase we decided to use it.
You can see an example by clicking on the style button that is on the homepage.
Orgianly the indiviaul pages such as artloth.html had four pictures the original, grayscale, sepia and opacity image.
When if orginal was clicked the user would be direct to the print/purchase page.
If the image with a filter was clicked such as grayscale, sepia, or opacity. The user was directed to another page that had the orginal
print, then the 3 filter settings for that option. Ex would be orginal, grayscale-min, grayscale and grayscale-max. When on of these
were clicked it lead the user to the print/purchase page.
###### Templeate Layout
For this progject I really wanted the website to look professional however I really did not want to use a template. So I started looking
into bootstrap.css on w3 and planned to do the online tutorial. That is when I found the w3.css tutorial. As I stated early the intro
page showed all the features and it seemed perfect for desiging by own layout for this page. I did look at the template for both
bootstrap and w3.css. None of them really meet what I wanted.
###### Color Scheme 
I love bright and vibrant colors. As seen on the orginal demo I had planned to use multiple bright colors for the page. I had even planned to customize the individual page color based on the individual art piece. Then I realized that the color scheme was taking away from the art work and did not look as professional so it was decided to go with a basic yellow theme which is Victoria's favorite color and is implemented in the stylesheet.css page. 




