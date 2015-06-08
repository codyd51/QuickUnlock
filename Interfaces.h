#import <objc/runtime.h>

#define kTweakName @"QuickLock"

#ifdef DEBUG
#define NSLog(FORMAT, ...) NSLog(@"[%@: %s / %i] %@", kTweakName, __FILE__, __LINE__, [NSString stringWithFormat:FORMAT, ##__VA_ARGS__])

#else
#define NSLog(FORMAT, ...) do {} while (0);
#endif

//#define CALL_ORIGIN NSLog(@"%s CALL_ORIGIN: [%@]", __PRETTY_FUNCTION__, [[[[NSThread callStackSymbols] objectAtIndex:1] componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"[]"]] objectAtIndex:1])
#define CALL_ORIGIN do {} while (0);

extern "C" CFNotificationCenterRef CFNotificationCenterGetDistributedCenter();

#define kSharedKey [[UIApplication sharedApplication] keyWindow]

@interface SBIcon : NSObject
@property (nonatomic, retain) NSString* applicationBundleID;
@end

@interface SBIconView : UIView {
	UIView* _labelView;
}
@property (nonatomic, assign) CGFloat iconLabelAlpha;
@property (nonatomic, retain) SBIcon* icon;
-(CGRect)iconImageFrame;
@end

@interface UIApplication (Private)
-(BOOL)launchApplicationWithIdentifier:(NSString*)identifier suspended:(BOOL)suspended;
@end

@interface SBIconModel : NSObject
-(NSDictionary*)iconState;
-(SBIcon*)expectedIconForDisplayIdentifier:(NSString*)ident;
@end

@interface SBIconListView : UIView
+(int)iconColumnsForInterfaceOrientation:(UIInterfaceOrientation)orient;
@end

@interface SBRootIconListView : SBIconListView
-(NSArray*)visibleIcons;
@end

@interface SBDockIconListView : SBIconListView
@end

@interface SBDockView : UIView
@end

@interface SBLockScreenView : UIView
- (void)scrollToPage:(long long)arg1 animated:(BOOL)arg2;
@end

@interface SBIconController : NSObject
@property (nonatomic, retain) SBIconModel* model;
+(id)sharedInstance;
-(SBRootIconListView*)currentRootIconList;
-(SBRootIconListView*)currentFolderIconList;
-(SBDockIconListView*)dockListView;
@end

@interface SBIconViewMap : NSObject
@property (nonatomic, retain) SBIconModel* iconModel;
+(id)homescreenMap;
-(SBIconView*)mappedIconViewForIcon:(SBIcon*)icon;
@end

@interface _UIBackdropViewSettings : NSObject
+(id)settingsForPrivateStyle:(int)style;
@end

@interface _UIBackdropView : UIView
-(id)initWithFrame:(CGRect)frame autosizesToFitSuperview:(BOOL)resizes settings:(_UIBackdropViewSettings*)settings;
@end
