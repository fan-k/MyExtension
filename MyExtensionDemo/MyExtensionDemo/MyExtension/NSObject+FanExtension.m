//
//  NSObject+FanExtension.m
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import "NSObject+FanExtension.h"
#import "FanDefine.h"
@implementation NSObject (FanExtension)

+ (CGSize)sizeWithFont:(UIFont *)font text:(NSString *)text maxWidth:(CGFloat)maxWidth {
    NSDictionary *attribute = @{NSFontAttributeName: font};
    CGRect rect = [text boundingRectWithSize:CGSizeMake(maxWidth, CGFLOAT_MAX)
                                     options:NSStringDrawingUsesLineFragmentOrigin
                                  attributes:attribute
                                     context:nil];
    return rect.size;
}

+ (CGSize)sizeWithFontSize:(CGFloat)fontSize text:(NSString *)text {
    return [self sizeWithFont:DefaultFontSize(fontSize) text:text maxWidth:CGFLOAT_MAX];
}

+ (CGSize)sizeWithBoldFontSize:(CGFloat)fontSize text:(NSString *)text {
    return [self sizeWithFont:DefaultFontSize(fontSize) text:text maxWidth:CGFLOAT_MAX];
}

+ (CGSize)sizeWithFontSize:(CGFloat)fontSize text:(NSString *)text maxWidth:(CGFloat)maxWidth {
    return [self sizeWithFont:DefaultFontSize(fontSize) text:text maxWidth:maxWidth];
}

+ (CGFloat)degreesToRadian:(CGFloat)degree {
    return (M_PI * degree) / 180.0;
}

+ (CGFloat)randianToDegrees:(CGFloat)radian {
    return (radian * 180.0) / M_PI;
}

+ (NSInteger)randomIntBetweenMin:(NSInteger)minValue andMax:(NSInteger)maxValue {
    return (NSInteger)(minValue + [self randomFloat] * (maxValue - minValue));
}

+ (CGFloat)randomFloat {
    return (float) arc4random() / UINT_MAX;
}

+ (CGFloat)randomFloatBetweenMin:(CGFloat)minValue andMax:(CGFloat)maxValue {
    return (((float) (arc4random() % ((unsigned)RAND_MAX + 1)) / RAND_MAX) * (maxValue - minValue)) + minValue;
}

+ (NSMutableData *)JSONDataWithObject:(id)object {
    NSMutableData *postBodyData = nil;
    
    if ([NSJSONSerialization isValidJSONObject:object]) {
        NSError *error = nil;
        NSData *postData = [NSJSONSerialization dataWithJSONObject:object
                                                           options:NSJSONWritingPrettyPrinted
                                                             error:&error];
        if (error) {
            NSLog(@"error: %@", error.description);
        } else {
            postBodyData = [[NSMutableData alloc] initWithData:postData];
        }
    }
    
    return postBodyData;
}

+ (NSString *)JSONStringWithObject:(id)object {
    NSMutableData *data = [self JSONDataWithObject:object];
    
    if (data.length) {
        return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    }
    
    return nil;
}

+ (BOOL)hasLocalInstallApp:(NSString *)urlSchemes {
    if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:urlSchemes]]) {
        return YES;
    }
    
    return NO;
}

+ (BOOL)canOpenApp:(NSString *)itunesUrlString {
    if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:itunesUrlString]]) {
        return YES;
    }
    
    return NO;
}

+ (void)openLocalApp:(NSString *)urlSchemes {
    if ([self canOpenApp:urlSchemes]) {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:urlSchemes]];
    }
}

+ (void)openAppStore:(NSString *)itunesUrlString {
#if TARGET_IPHONE_SIMULATOR
    NSLog(@"虚拟机不支持APP Store.打开iTunes不会有效果。");
#else
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:itunesUrlString]];
#endif
    return;
}

- (void)setValue:(id)value forUndefinedKey:(NSString *)key {
    
}

- (NSString *)className {
    return NSStringFromClass([self class]);
}

+ (id)removeNullFromObject:(id)object {
    if ([object isKindOfClass:[NSDictionary class]]) {
        return [self _removeNullFromDict:(NSDictionary *)object];
    } else if ([object isKindOfClass:[NSArray class]]) {
        return [self _removeNullFromArray:(NSArray *)object];
    } else if ([object isKindOfClass:[NSNull class]] || object == nil) {
        return nil;
    }
    
    return object;
}

+ (NSDictionary *)_removeNullFromDict:(NSDictionary *)dict {
    if (dict == nil || [dict isKindOfClass:[NSNull class]]) {
        return nil;
    }
    
    NSMutableDictionary *resultDict = [NSMutableDictionary dictionaryWithCapacity:dict.count];
    for (id key in dict.allKeys) {
        id object = [dict objectForKey:key];
        
        if ([object isKindOfClass:[NSNull class]] || object == nil) {
            // 不添加
        } else if ([object isKindOfClass:[NSDictionary class]]) {
            object = [self _removeNullFromDict:(NSDictionary *)object];
            
            if (object != nil) {
                [resultDict setObject:object forKey:key];
            }
        } else if ([object isKindOfClass:[NSArray class]]) {
            object = [self _removeNullFromArray:(NSArray *)object];
            
            if (object != nil) {
                [resultDict setObject:object forKey:key];
            }
        } else {
            [resultDict setObject:object forKey:key];
        }
    }
    
    return resultDict;
}

+ (NSArray *)_removeNullFromArray:(NSArray *)array {
    if (array == nil || [array isKindOfClass:[NSNull class]]) {
        return nil;
    }
    
    if (array.count == 0) {
        return array;
    }
    
    NSMutableArray *resultArray = [[NSMutableArray alloc] initWithCapacity:array.count];
    
    for (NSUInteger i = 0; i < array.count; ++i) {
        id object = array[i];
        
        if ([object isKindOfClass:[NSNull class]] || object == nil) {
            // 不添加
        } else if ([object isKindOfClass:[NSDictionary class]]) {
            object = [self _removeNullFromDict:(NSDictionary *)object];
            if (object != nil && ![object isKindOfClass:[NSNull class]]) {
                [resultArray addObject:object];
            }
        } else if ([object isKindOfClass:[NSArray class]]) {
            object = [self _removeNullFromArray:(NSArray *)object];
            if (object != nil && ![object isKindOfClass:[NSNull class]]) {
                [resultArray addObject:object];
            }
        } else {
            [resultArray addObject:object];
        }
    }
    
    return resultArray;
}
@end
