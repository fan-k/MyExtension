//
//  NSMutableDictionary+FanExtension.m
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import "NSMutableDictionary+FanExtension.h"

@implementation NSMutableDictionary (FanExtension)
- (void)setSafeObject:(id)anObject forKey:(id<NSCopying>)aKey {
    if (aKey == nil) {
        return;
    }
    
    if (anObject == nil) {
        return;
    }
    
    if ([anObject isKindOfClass:[NSString class]]) {
        NSString *obj = (NSString *)anObject;
        if (obj.length == 0) {
            return;
        }
    }
    
    [self setObject:anObject forKey:aKey];
}

- (void)setInt:(int)intValue forKey:(id<NSCopying>)aKey {
    [self setSafeObject:@(intValue) forKey:aKey];
}

- (void)setDouble:(double)doubleValue forKey:(id<NSCopying>)aKey {
    [self setSafeObject:@(doubleValue) forKey:aKey];
}

- (void)setFloat:(float)floatValue forKey:(id<NSCopying>)aKey {
    [self setSafeObject:@(floatValue) forKey:aKey];
}
@end
