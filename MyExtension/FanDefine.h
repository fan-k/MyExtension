//
//  FanDefine.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#ifndef FanDefine_h
#define FanDefine_h



//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//NSUSerDefault
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]
/**
 * MainScreen Height Width
 *根据目前设备的尺寸大小 得到的宽高不分横竖屏
 */
#define FScreenHeight ([[UIScreen mainScreen] bounds].size.height > 450 ? [[UIScreen mainScreen] bounds].size.height : [[UIScreen mainScreen] bounds].size.width )//主屏幕的高度
#define FScreenWidth  ([[UIScreen mainScreen] bounds].size.width > 450 ? [[UIScreen mainScreen] bounds].size.height :[[UIScreen mainScreen] bounds].size.width) //主屏幕的宽度
#define FScreenBounds [UIScreen mainScreen].bounds               //主屏幕bounds
//NSLog
#ifdef DEBUG

#define FLog( s, ... ) NSLog( @"< %@:(%d) ----: %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )

#else

#define FLog( s, ... )

#endif
// image
// Only load png image successfully.
#define FImageWithName(Name) ([UIImage imageNamed:Name])
#define FBigImageWithName(Name) ([UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:Name ofType:nil]])

// color
///< format：0xFFFFFF
#define F16RGBColor(rgbValue) \
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 \
green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 \
blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:1.0]
///< format：22,22,22
#define FRGBColor(r, g, b) ([UIColor colorWithRed:(r) / 255.0  \
green:(g) / 255.0  \
blue:(b) / 255.0  \
alpha:1])
///< format：22,22,22,0.5
#define kRGBAColor(r, g, b, a) ([UIColor colorWithRed:(r) / 255.0  \
green:(g) / 255.0  \
blue:(b) / 255.0  \
alpha:(a)])

// tab bar / navigation bar
#define FNavBarHeight  (44.0)
#define FStatusBarHeight (20.0)
#define FTabBarHeight (49.0)
//判断系统版本
#define OpinionVesion   __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_8_2
//字体大小（常规/粗体）
#define DefaultBoldFontSize(FONTSIZE)  OpinionVesion ?[UIFont systemFontOfSize:FONTSIZE weight:UIFontWeightBold]:[UIFont fontWithName:@"CourierNewPSMT" size:FONTSIZE]
#define DefaultFontSize(FONTSIZE)      OpinionVesion ?[UIFont systemFontOfSize:FONTSIZE weight:UIFontWeightLight]:[UIFont fontWithName:@"CourierNewPSMT" size:FONTSIZE]
#define FontNameAndSize(NAME,FONTSIZE)      [UIFont fontWithName:(NAME) size:(FONTSIZE)]

// string format
#define FStringFormat(format, params) ([NSString stringWithFormat:format, params])

// weak / strong object
#define FWeakObject(object) __weak typeof(object) weakObject = object;
#define FStrongObject(object) __strong typedef(object) strongObject = object;

// main thread / global thread
#define FMainThread (dispatch_get_main_queue())
#define FGlobalThread dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)
// singleton
#define FUserDefaults [NSUserDefaults standardUserDefaults]
#define FNotificationCenter  [NSNotificationCenter defaultCenter]

#define FPostNotificationWithName(notificationName) \
[kNotificationCenter postNotificationName:notificationName object:nil userInfo:nil]

#define FPostNotificationWithNameAndUserInfo(notificationName, userInfo) \
[kNotificationCenter postNotificationName:notificationName object:nil userInfo:userInfo]

// empty
#define FIsEmptyString(s) (s == nil || [s isKindOfClass:[NSNull class]] || ([s isKindOfClass:[NSString class]] && s.length == 0))

#define kIsNull(obj) ([obj isKindOfClass:[NSNull class]])

//判断设备类型
#define iPhone4 ([UIScreen mainScreen].bounds.size.height == 480)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size)) : NO)
#define iPhone6plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)) : NO)

#define iPhone6_6s  ([UIScreen mainScreen].bounds.size.width >= 375)
#endif /* FanDefine_h */


