//
//  NSMutableDictionary+FanExtension.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (FanExtension)
/**
 * 调用此方法来防止无效值时崩溃的问题
 */
- (void)setSafeObject:(id)anObject forKey:(id<NSCopying>)aKey;
- (void)setInt:(int)intValue forKey:(id<NSCopying>)aKey;
- (void)setDouble:(double)doubleValue forKey:(id<NSCopying>)aKey;
- (void)setFloat:(float)floatValue forKey:(id<NSCopying>)aKey;

@end
