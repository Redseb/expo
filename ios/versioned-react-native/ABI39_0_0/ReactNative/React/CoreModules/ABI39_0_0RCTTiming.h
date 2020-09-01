/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import <ABI39_0_0React/ABI39_0_0RCTBridgeModule.h>
#import <ABI39_0_0React/ABI39_0_0RCTFrameUpdate.h>
#import <ABI39_0_0React/ABI39_0_0RCTInvalidating.h>

@protocol ABI39_0_0RCTTimingDelegate

- (void)callTimers:(NSArray<NSNumber *> *)timers;
- (void)immediatelyCallTimer:(nonnull NSNumber *)callbackID;
- (void)callIdleCallbacks:(nonnull NSNumber *)absoluteFrameStartMS;

@end

@interface ABI39_0_0RCTTiming : NSObject <ABI39_0_0RCTBridgeModule, ABI39_0_0RCTInvalidating, ABI39_0_0RCTFrameUpdateObserver>

- (instancetype)initWithDelegate:(id<ABI39_0_0RCTTimingDelegate>)delegate;
- (void)createTimerForNextFrame:(nonnull NSNumber *)callbackID
                       duration:(NSTimeInterval)jsDuration
               jsSchedulingTime:(NSDate *)jsSchedulingTime
                        repeats:(BOOL)repeats;
- (void)deleteTimer:(double)timerID;

@end
