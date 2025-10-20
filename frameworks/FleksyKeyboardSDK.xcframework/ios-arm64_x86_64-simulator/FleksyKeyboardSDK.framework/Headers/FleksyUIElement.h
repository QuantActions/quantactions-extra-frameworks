//
//  FleksyUIElement.h
//  FleksyiOS
//
//  Created by Ben Pious on 3/4/15.
//  Copyright (c) 2015 Thingthing, Ltd. All rights reserved.
//

#import "FKEnums.h"
#import "FleksyThemeableUI.h"

@class FleksyLayoutElement;

/**
 All keyboard layout objects conform to this protocol.
 */
@protocol FleksyUIElement <NSObject, FleksyThemeableUI>

@property (nonatomic) int uniqueID;
@property (nonatomic) ButtonType buttonType;
@property (nonatomic) BOOL isShowingCursorControl;
- (void)setDimmed:(BOOL)dimm animated:(BOOL)animated;

/// Sets the frame of the receiver applying certain margins to the passed rect.
/// The actual frame is usually set to an inset rect.
- (void)setFrameApplyingMarginsToFrame:(CGRect)frame;

/// Restores the key after interactions with animations.
/// - Parameter duration: The duration for the animation to hide the key pop.
///
/// Currently only the hiding of the key popups can be animated. If the key/button is highlighted, no animation happens when it unhighlights.
- (void)restoreWithAnimationDuration:(NSTimeInterval)duration;

/// Being associated to `element` can mean different things for different UI elements. There can be 2 different buttons associated to the same `FleksyLayoutElement` (for example, two different Shift buttons in the same keyboard layout).
- (BOOL)isAssociatedToElement:(FleksyLayoutElement * _Nonnull)element;

@end
