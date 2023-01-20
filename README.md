The Card Game Template serves as a good starting point for creating a card game. It allows a developer to create their own 
cards and customize the field they will be used on. They can also use the manager to help create a flow to their game. 
Each card can be given stats and effects to grant indiviuality to each card.

## How It Works

The system works a one big unit, but each part can be seperated into sections.

The Main part of the system is the PrimaryCardDataAsset. This contains the data the card will hold. While the base version doesn't contain much, the developer can add several variables to customize them.

The Card actor is the physical repersentation of the cards. It acts as a vessel for the Card Data Assets to manipulate.

The PlayZone as well as the other zones are the field that the game is played on. All of the zone the develop wishes to use or create should inherit from PlayZone. FieldZone contains the cards that are played, while the deck and discard piles hold cards in the deck and that are removed from the field respectively.

The CardGamePawn is the player's class. It hold the hand as well as references to many other things on the field. It also contains several functions that allow it to manipulate the game in the way the developer would want it too.

The PlayerDeck and Inventory Components are used for the DeckBuilding aspect of the template. It holds the cards that the players will use in their deck as well as all the cards they own.

Finally the CardGameManager controls the flow of the game.

## How To Use

The developer should start by editting the PrimaryCardDataAsset to contain the variables that their cards will have. This usually will include the name, stats and card text. After the developer should also add these variables to the card actor, this is because the data asset is shared amongst its refernces and are also changed in the editor when changed in game.

The Developer then can create the field they want, using the provided zone or zones they created.
They should also ensure that each zone has its owner determined, as certain issue can arrise if not.

The Developer can also then edit the CardGameManager to control the flow of the game, win conditions, and initializing the game.