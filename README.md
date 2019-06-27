# Freecell_solitaire

Developed this code for "Freecell solitaire" which checks for every move made by the player. If a valid move, it would make those specific changes to the board otherwise would not let one move. This code was developed using the Module interface Specification which can be found under the "report" directory.

Thank you and feel free to check if you are making a valid move or not :)

# KODI
---
### Purpose

Our vision is to maximize our employees’ utilization of provided RBC applications by providing immediate and concise application support and resources.

Currently, retrieving application information within RBC is a long and sometimes inaccessible process, especially for new employees. It is challenging to find sufficient information regarding various applications on IIPM do to the complexity of provided reports that are sometimes outdated. Moreover, app codes are key in knowing applications, and currently mean very little for anyone who does not play a development-related role. It is also difficult to contact support for applications if the user is unfamiliar with application functionality.

Kodi is an employee application support and search engine that aims to encourage and maximize the use of RBC tools in order to optimize productivity of RBC application users. Kodi provides a concise summary regarding IIPM support and those responsible for RBC applications.

### Tech

Kodi uses the following tech(s) to work properly:
* [NodeJS](https://nodejs.org/) - JavaScript enhanced for the slack bot!! evented I/O for the backend
* [Microsoft Visual Studio](https://visualstudio.microsoft.com/) - IDE to run this application.

### User Manual

***Note: Kodi is not case sensitive***

1. When Kodi says “How can I help you?“, please enter “rbc app” to start!

2. Once the application starts, there will be three options popping up:

                  a. Search app by its name
                  
                  b. Search by its app code
                  
                  c. Search by Contact Person’s name
                  
     You can enter a, b or c according to your needs
          
3. Depending on the option you have selected, Kodi will ask you to provide more information such as App Name, App Code or Contact Person’s name.
          
4. All the url and email links are clickable
                  a. When you click on an url link, it will open a new tab with that url
                  b. When you click on an email link, it will open a new email draft with that email

5. When Kodi asks if you would like to view more information after the search completes, please enter the answer states within “()”
                  e.g., (Yes/No) means you can confirm by entering ‘yes’ to view additional information

6. Enjoy your time with Kodi!
          
### Installation

Kodi requires [Node.js](https://nodejs.org/)  to run.

Install the dependencies and devDependencies and start the server.

```sh
$ npm i slackbots
```

### New Features!

Kodi lets you search for following 3 things:

> App Name

-Lets you search by the app name and will return you App Code, Description, Tech Stack, TDD Link, MPP Link, Contact person and their email.

> App Code

-Lets you search by the app name and will return you App Name, Description, Tech Stack, TDD Link, MPP Link, Contact person and their email.

>Contact Person

-Lets you search by name and returns all the app name under that person. Further, lets you get all the details for each app.

Also, all of the options give u further choice of getting team information of each app code

### Plugins

Kodi is currently extended with the following plugins. Instructions on how to use them in your own application are linked below.

| Plugin | README | Description |
| ------ | ------ | ----------- |
| Github | [team3/README.md](https://github.com/) | The Github repository with README and code files|
| Data   | [data.js] | The data file consisting the Dataset for this slackbot |
| Application | [server.js] | The code file |

