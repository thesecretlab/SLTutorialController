//
//  SLTutorialController.h
//  Tutorial System Controller
//
//  Created by Jon Manning on 29/05/12.
//  Copyright (c) 2012 Secret Lab. All rights reserved.
//

/* 
 SLTutorialController is a class that manages the user's progression through
 a linear tutorial. 

 To use it, you list all of the stages in your tutorial in the SLTutorialStage enum.

 You can get the current status of the tutorial like this:

 if ([SLTutorialController sharedController].tutorialStage == SLTutorialBuildABuilding) {
      // display the relevant tutorial stuff for this stage
 }

 When the user performs an action that completes a stage in the tutorial, you
 do this. 

 [[SLTutorialController sharedController] tutorialStagePerformed:SLTutorialSelectAUnit];
 
 SLTutorialController will only advance the tutorial if and only if the current tutorial stage is the one that was reported as complete. This means that your code doesn't need to worry about being in a "tutorial mode".

 SLTutorialController posts a SLTutorialStageUpdated notification whenever the tutorial stage changes.
 
*/

#import <Foundation/Foundation.h>

extern NSString* const SLTutorialStageUpdated;
extern NSString* const SLTutorialStageKey;

// List all of the stages in the tutorial. 
// The user must perform these steps in order.
// Leave the last step as SLTutorialComplete.
typedef enum  {

// ***** v EDIT THIS PART v *****

// These are sample tutorial steps. You'll want to replace them.

    SLTutorialBuildABuilding = 0,   // step 1, build a building
    SLTutorialSelectAUnit,          // step 2, select a unit
    SLTutorialDefeatAnEnemy,        // step 3, defeat an enemy
    SLTutorialComplete              // tutorial complete
// ***** ^ EDIT THIS PART ^ *****

} SLTutorialStage;

// Delegates are asked for the current help text key.
@protocol SLTutorialControllerHelpDelegate <NSObject>

- (NSString* const) helpTextKeyForCurrentGameState;

@end

@interface SLTutorialController : NSObject

// Get the singleton SLTutorialController object.
+ (SLTutorialController*)sharedController;

// The current stage of the tutorial.
@property (readonly) SLTutorialStage tutorialStage;

// Reset the tutorial to the start.
- (void) resetTutorial;

// If 'stage' is equal to the current tutorial stage, progress to the next one and 
// post an SLTutorialStageUpdated notification.
- (void) tutorialStagePerformed:(SLTutorialStage)stage;

@end
