//
//  FleksyButton.h
//  FleksyKitContainerApp
//
//  Created by Tusi Chowdhury on 2014-07-29.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FleksyTheme.h"
#import "FleksyDefines.h"
#import "FleksyUIElement.h"
#import "FleksyThemeableUI.h"
#import "FleksyVibrantViewContainer.h"

typedef NS_OPTIONS(NSInteger, FleksyButtonStyleClass) {
  FleksyButtonStyleClassDefault       = 1 << 0,   // Full opacity title(icon), semi-transparent background
  FleksyButtonStyleClassTransparent   = 1 << 1,   // No background, semi-transparent title(icon), except when selected
  FleksyButtonStyleClassHomeRow       = 1 << 2,   // Background matches the home row
  FleksyButtonStyleClassRounded       = 1 << 3,   // Rounded corners
  FleksyButtonStyleClassShadow        = 1 << 4,   // TODO: Applies the shadow color at the bottom of the frame
  FleksyButtonStyleClassForeground    = 1 << 5,   //Transparent, but full opacity title
  FleksyButtonStyleClassLongPressHint = 1 << 6,   //Has three rounded circles indicating that it is possible to tap and hold on the button
  FleksyButtonStyleClassFlick         = 1 << 7,   // japanese hacks
};

typedef NS_ENUM(NSInteger, FleksyVibrancyStyle) {
  FleksyVibrancyStyleNone,
  FleksyVibrancyStyleLight,
  FleksyVibrancyStyleDark
};

typedef int FleksyInterfaceMode;

/**
 A button which can manage its own theme and layouting, including corner buttons. Used for all keypad buttons.
 */
@interface FleksyButton : UIControl <FleksyUIElement, FleksyThemeableUI, FleksyVibrantViewContainer>

@property (nonatomic, strong) UIColor *backgroundColorFleksy;
@property (nonatomic) FleksyTheme * _Nullable theme;
@property (nonatomic, strong) UIColor *selectedColor;
@property (nonatomic) FleksyVibrancyStyle vibrancyStyle;
@property (nonatomic, strong) UIVibrancyEffect *vibrancyEffect;
@property (nonatomic, readonly) NSString *currentTitle;
@property (nonatomic, readonly) BOOL inFlickKeyboard;
@property (nonatomic, readonly) KeyboardStyle keyboardStyle;

/// When this property is `true`, depending on the `interfaceMode`, the title label can be shifted to the left or right on some iPad models. Defaults to `false`. Ignored for jp-JP Flick layout, where title shifting is never allowed.
@property (assign, nonatomic) BOOL allowsTitleShifting;

/// The `displayLabel` of the associated `FleksyLayoutElement`.
@property (copy, nonatomic, readonly) NSString *elementDisplayLabel;

- (instancetype)initWithDisplayLabel:(NSString * _Nonnull)displayLabel
                               theme:(FleksyTheme * _Nullable)theme
                     inFlickKeyboard:(BOOL)inFlickKeyboard
                          styleClass:(FleksyButtonStyleClass)styleClass
                       keyboardStyle:(KeyboardStyle)keyboardStyle; // should this also take a frame?
- (void)setShouldUseLabelShadowWithColor:(UIColor *)labelShadowColor;

/// Triggers the total dissappearing animation with no delay.
- (void)triggerDisappearAnimationForView:(UIView *)disappearingView;

/// Triggers the dissappearing animation to `endingAlpha` with a delay.
- (void)triggerDisappearAnimationForView:(UIView *)disappearingView
                             endingAlpha:(CGFloat)endingAlpha
                        andStartingAlpha:(CGFloat)startingAlpha;
- (void)setTitle:(NSString *)aTitle
        forState:(UIControlState)state;
- (void)setTitleColor:(UIColor *)color
             forState:(UIControlState)state;
- (void)setTitleColors;
- (UIColor *)buttonBackgroundColor;
/// To reflect any changes in `buttonBackgroundColor`.
- (void)updateBackgroundColor;
- (UIColor *)pressedButtonBackgroundColor;
- (CGFloat)alphaForState:(UIControlState)state;
- (NSString *)titleForState:(UIControlState)state;
- (UIColor *)titleColorForState:(UIControlState)state;
- (void)triggerTitleFadeAnimationWithAlpha:(CGFloat)alpha;
- (void)changeType:(ButtonType)type;
- (void)showTextLabel;
- (void)hideTextLabel;
- (void)showLongPressHint;

/// Changes the title and displays it with the given font.
///
/// The `interfaceMode` is used to shift the title label of the button to the left or right on some iPad models. To disable title shifting, set
- (void)changeToCustomTitle:(NSString *)customTitle font:(UIFont *)font interfaceMode:(FleksyInterfaceMode)interfaceMode;

/// Displays the given icon title with the Fleksy font.
- (void)changeToIconTitle:(NSString *)iconTitle interfaceMode:(FleksyInterfaceMode)interfaceMode;

/// Displays the given SF symbol in the button.
- (void)changeToSFSymbolTitle:(NSString * _Nonnull)sfSymbol mirrored:(BOOL)mirrored interfaceMode:(FleksyInterfaceMode)interfaceMode;

@end
