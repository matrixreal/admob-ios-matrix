#import <UIKit/UIKit.h>
#import <Cordova/CDV.h>
#import <Cordova/CDVPlugin.h>
#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
#import <GoogleMobileAds/GADExtras.h>
#import <GoogleMobileAds/GADAdSize.h>
#import <GoogleMobileAds/GADBannerView.h>
#import <GoogleMobileAds/GADInterstitial.h>
#import <GoogleMobileAds/GADRewardBasedVideoAd.h>
#import <GoogleMobileAds/GADBannerViewDelegate.h>
#import <GoogleMobileAds/GADInterstitialDelegate.h>
#import <GoogleMobileAds/GADRewardBasedVideoAdDelegate.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <UserMessagingPlatform/UserMessagingPlatform.h>
#import <AdSupport/ASIdentifierManager.h>
#import <AdSupport/AdSupport.h>

#pragma mark - JS requestAd options

@class GADBannerView;

@class GADInterstitial;

@class GADRewardBasedVideoAd;

#pragma mark AdMob Plugin

// This version of the AdMob plugin has been tested with Cordova version 9.0.0.

@interface CDVAdMob : CDVPlugin <GADBannerViewDelegate, GADInterstitialDelegate, GADRewardBasedVideoAdDelegate> {
    @protected
    UIView* _safeAreaBackgroundView;
}

@property (nonatomic, retain) GADBannerView *bannerView;
@property (nonatomic, retain) GADInterstitial *interstitialView;
@property (nonatomic, retain) GADRewardBasedVideoAd *rewardVideoView;

@property (nonatomic, retain) NSString* publisherId;
@property (nonatomic, retain) NSString* interstitialAdId;
@property (nonatomic, retain) NSString* rewardVideoId;


@property (assign) GADAdSize adSize;
@property (assign) BOOL bannerAtTop;
@property (assign) BOOL bannerOverlap;
@property (assign) BOOL offsetTopBar;

@property (assign) BOOL isTesting;
@property (nonatomic, retain) NSDictionary* adExtras;

@property (assign) BOOL bannerIsVisible;
@property (assign) BOOL bannerIsInitialized;
@property (assign) BOOL bannerShow;
@property (assign) BOOL autoShow;
@property (assign) BOOL autoShowBanner;
@property (assign) BOOL autoShowInterstitial;
@property (assign) BOOL autoShowRewardVideo;
@property (assign) NSObject* rewardedVideoLock;
@property (assign) BOOL isRewardedVideoLoading;


@property (nonatomic, retain) NSString* gender;
@property (nonatomic, retain) NSString* forChild;

- (void) setOptions:(CDVInvokedUrlCommand *)command;
- (void) getTrackingStatus:(CDVInvokedUrlCommand *)command;
- (void) trackingStatusForm:(CDVInvokedUrlCommand *)command;
- (void) userMessagingPlatform:(CDVInvokedUrlCommand*)command;

- (void) createBannerView:(CDVInvokedUrlCommand *)command;
- (void) destroyBannerView:(CDVInvokedUrlCommand *)command;
- (void) requestAd:(CDVInvokedUrlCommand *)command;
- (void) showAd:(CDVInvokedUrlCommand *)command;

- (void) createInterstitialView:(CDVInvokedUrlCommand *)command;
- (void) requestInterstitialAd:(CDVInvokedUrlCommand *)command;
- (void) showInterstitialAd:(CDVInvokedUrlCommand *)command;
- (void) isInterstitialReady:(CDVInvokedUrlCommand *)command;

- (void) createRewardVideo:(CDVInvokedUrlCommand *)command;
- (void) showRewardVideo:(CDVInvokedUrlCommand *)command;
- (void) isRewardVideoReady:(CDVInvokedUrlCommand *)command;

@end
