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

/// Called when the keyboard is showing a temporary with the receiver key as the origin.
///
/// For example, when long pressing the "A" key to get accents: "Á", "À", etc.
- (void)highlightForTemporaryKeypad;
- (void)restore;
- (void)dragPopWithShiftY:(CGFloat)shiftY
                 duration:(NSTimeInterval)duration
                isSidePop:(BOOL)isSidePop;
- (void)containerSwiped:(FleksyTouchSwipeDirection)swipeDirection;

@end
