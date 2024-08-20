//  PerformanceDelegate.h
//  FleksyKeyboardSDK
//
//  Copyright © 2023 Thingthing. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol PerformanceDelegate <NSObject>

- (BOOL)performanceTrackingEnabled;

// Firebase Performance style API
- (void)startEvent:(NSString *)name;
- (void)updateEvent:(NSString *)name withValue:(NSString *)value forAttribute:(NSString *)attribute;
- (void)incrementMetric:(NSString *)metricName forEvent:(NSString *)eventName;
- (void)endEvent:(NSString *)name;

// Methods providing execution duration info
- (void)measureEvent:(NSString *)name timeElapsedInMillis:(NSInteger)milliseconds attributes:(NSDictionary<NSString *, NSString *> *)attributes;

@end

NS_ASSUME_NONNULL_END
