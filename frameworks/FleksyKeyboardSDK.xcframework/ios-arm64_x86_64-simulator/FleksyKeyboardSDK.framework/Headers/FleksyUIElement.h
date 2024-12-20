//
//  FleksyUIElement.h
//  FleksyiOS
//
//  Created by Ben Pious on 3/4/15.
//  Copyright (c) 2015 Thingthing, Ltd. All rights reserved.
//

#import "FKEnums.h"

/**
 All keyboard layout objects conform to this protocol.
 */
@protocol FleksyUIElement <NSObject>

@property (nonatomic) int uniqueID;
@property (nonatomic) ButtonType buttonType;
- (void)setDimmed:(BOOL)dimm animated:(BOOL)animated;

/// Sets the frame of the receiver applying certain margins to the passed rect.
/// The actual frame is usually set to an inset rect.
- (void)setFrameApplyingMarginsToFrame:(CGRect)frame;

@end
