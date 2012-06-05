//
//  SLTutorialController.m
//  Tutorial System Controller
//
//  Created by Jon Manning on 29/05/12.
//  Copyright (c) 2012 Secret Lab. All rights reserved.
//

#import "SLTutorialController.h"

NSString* const SLTutorialStageUpdated = @"SLTutorialStageUpdated";
NSString* const SLTutorialStageKey = @"tutorial_stage";

static SLTutorialController* _sharedController = nil;

@interface SLTutorialController () {
    SLTutorialStage _stage;
}

@end

@implementation SLTutorialController

@dynamic tutorialStage;
@dynamic hintText;

- (id)init
{
    self = [super init];
    if (self) {
        _stage = [[NSUserDefaults standardUserDefaults] integerForKey:SLTutorialStageKey];
    }
    return self;
}

+ (SLTutorialController*)sharedController {
    if (_sharedController == nil) {
        _sharedController = [[SLTutorialController alloc] init];
    }
    return _sharedController;
}

- (SLTutorialStage) tutorialStage {
    return _stage;
}

- (void) setTutorialStage:(SLTutorialStage)stage {
    _stage = stage;
    [[NSUserDefaults standardUserDefaults] setInteger:_stage forKey:SLTutorialStageKey];
    NSDictionary* userInfo = [NSDictionary dictionaryWithObject:[NSNumber numberWithInt:_stage] forKey:SLTutorialStageKey];
    [[NSNotificationCenter defaultCenter] postNotificationName:SLTutorialStageUpdated object:self userInfo:userInfo];
}

- (void) resetTutorial {
    [self setTutorialStage:0];
}

- (void) tutorialStagePerformed:(SLTutorialStage)stage {
    if (stage == _stage) {
        [self setTutorialStage:_stage+1];        
    }
}

@end
