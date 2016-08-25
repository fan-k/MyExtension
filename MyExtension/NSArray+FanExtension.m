//
//  NSArray+FanExtension.m
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import "NSArray+FanExtension.h"

@implementation NSArray (FanExtension)
- (id)safeObjectAtIndex:(NSUInteger)index {
    NSUInteger count = [self count];
    
    if (count > 0 && index < count) {
        return [self objectAtIndex:index];
    }
    
    return nil;
}

- (NSArray *)reversedArray {
    return [NSArray reversedArray:self];
}

+ (NSArray *)reversedArray:(NSArray *)array {
    NSMutableArray *arrayTemp = [NSMutableArray arrayWithCapacity:[array count]];
    NSEnumerator *enumerator = [array reverseObjectEnumerator];
    
    for (id element in enumerator) {
        [arrayTemp addObject:element];
    }
    
    return array;
}

- (NSString *)toJson {
    return [NSArray toJson:self];
}

+ (NSString *)toJson:(NSArray *)array {
    if (![array isKindOfClass:[NSArray class]] || array == nil || array.count == 0) {
        return nil;
    }
    NSString *json = nil;
    NSError *error = nil;
    NSData *data = [NSJSONSerialization dataWithJSONObject:array options:0 error:&error];
    
    if (!error) {
        json = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        return json;
    }
    
    return nil;
}

- (BOOL)isContainsString:(NSString *)string {
    for (NSString *element in self) {
        if ([element isKindOfClass:[NSString class]] && [element isEqualToString:string]) {
            return true;
        }
    }
    
    return false;
}
@end
