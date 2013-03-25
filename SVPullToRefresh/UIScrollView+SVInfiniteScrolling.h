//
// UIScrollView+SVInfiniteScrolling.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
//

#import <UIKit/UIKit.h>

@class SVInfiniteScrollingView;

@interface UIScrollView (SVInfiniteScrolling)

- (void)addInfiniteScrollingWithActionHandler:(void (^)(void))actionHandler;
- (void)triggerInfiniteScrollingAnimated:(BOOL)animated;

@property (nonatomic, strong, readonly) SVInfiniteScrollingView *infiniteScrollingView;
@property (nonatomic, assign) BOOL showsInfiniteScrolling;
- (void)setShowsInfiniteScrolling:(BOOL)showsInfiniteScrolling animated:(BOOL)animated;

@end


enum {
    SVInfiniteScrollingStateStopped = 0,
    SVInfiniteScrollingStateTriggered,
    SVInfiniteScrollingStateLoading,
    SVInfiniteScrollingStateAll = 10
};

typedef NSUInteger SVInfiniteScrollingState;

@interface SVInfiniteScrollingView : UIView

@property (nonatomic, readwrite) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
@property (nonatomic, readonly) SVInfiniteScrollingState state;
@property (nonatomic, readwrite) BOOL enabled;
@property (nonatomic, retain) UIScrollView *dragScrollView;

- (void)setCustomView:(UIView *)view forState:(SVInfiniteScrollingState)state;

- (void)startAnimatingAnimated:(BOOL)animated;
- (void)stopAnimatingAnimated:(BOOL)animated;

@end
