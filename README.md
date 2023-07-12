


**#gipPlayfab**

[Work in Progress]

  

**First Setup**

  

Make sure you set the titleID in the gipPlayfab.h file. You can get your title's titleID inside the Playfab Developer Page.

  

Register a player using the registerPlayFabAccount method by giving it it's required parameters (username, email, password, display name). Then run the program. If successful a message in the console stating that the account is registered and the player with it's account can be seen and edited in the Player List in the Playfab Developer Page.

  

**IMPORTANT NOTE:** After the first registration, do not re-register the player.

  

To login simply use the login method and give it's parameters (username, password) and run the program.

If successful a message in the console stating that the Login is successful and the Session Information.

  

**Note:** Most 3rd party antivirus softwares might cause the plugin to not work. Stopping/pausing the antivirus software solves the issue.

  

**Setting Up Matchmaking Tickets**

  

Set up a new Queue in the Multiplayer section of the Playfab Developer Page then set the myqueuename in the gipPlayfab.h file

  

Create a matchmaking ticket using the createMatchmakingTicket() method and give it's parameter (giveupafterseconds) a value. Values between 90 - 150 works the best.

If successful in the console a message saying the Matchmaking Ticket has been created and then your Matchmaking Ticket Id will be sent

  

Check the matchmaking ticket to enter a match using the checkMatchmakingTicket() method and it's parameters require you to enter the Matchmaking Ticket Id. To get your Matchmaking Ticket Id use the getTicketId() method for it's parameter.

If more than one device is successfull a message saying the match has been found will be sent

If only one device is successfull then the message will say that it's waiting for match
