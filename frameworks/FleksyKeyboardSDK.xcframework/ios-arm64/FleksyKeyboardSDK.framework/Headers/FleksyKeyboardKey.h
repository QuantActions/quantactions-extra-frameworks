//  FleksyKeyboardKey.h
//  FleksyKeyboardSDK
//
//  Copyright © 2024 Thingthing. All rights reserved.
//

/// The protocol implemented by keyboard keys (`FleksyKey` and `FleksyFlickKey`).
@protocol FleksyKeyboardKey <FleksyUIElement>

@property (nonatomic) NSString *letter;
@property (nonatomic) UIFont *letterFont;
@property (nonatomic) UIFont *lowercaseLetterFont;

- (void)highlight;
- (void)pop;
- (void)longPressPop;
- (void)restore;
- (void)restoreWithAnimationDuration:(NSTimeInterval)duration;
- (void)dragPopWithShiftY:(CGFloat)shiftY
                 duration:(NSTimeInterval)duration
                isSidePop:(BOOL)isSidePop;
- (void)containerSwiped:(FleksyTouchSwipeDirection)swipeDirection;

@end
