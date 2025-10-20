//
//  FleksyEmojiHintButton.h
//  FleksyKitContainerApp
//
//  Created by Ross Beale on 12/09/2014.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import "FleksyButton.h"

/**
 FleksyButton with an emoji hint
 
 TODO: make a convenience method to create a button with an emoji for its corner icon
 */
@interface FleksyEmojiHintButton : FleksyButton

@property (nonatomic, strong) UILabel *cornerIconView;

- (instancetype)initWithIcon:(NSString *)iconChar
                  cornerIcon:(NSString *)cornerIconChar
                       theme:(FleksyTheme *)aTheme
             inFlickKeyboard:(BOOL)inFlickKeyboard
                  styleClass:(FleksyButtonStyleClass)aStyleClass
               keyboardStyle:(KeyboardStyle)keyboardStyle;

@end
