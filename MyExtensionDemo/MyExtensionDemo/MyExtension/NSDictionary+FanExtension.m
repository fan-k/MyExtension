//
//  NSDictionary+FanExtension.m
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#import "NSDictionary+FanExtension.h"

@implementation NSDictionary (FanExtension)
+ (id)changeType:(id)obj
{
    if ([obj isKindOfClass:[NSDictionary class]])
        return [self nullDic:obj];
    else if([obj isKindOfClass:[NSArray class]])
        return [self nullArr:obj];
    else if([obj isKindOfClass:[NSString class]])
        return [self stringToString:obj];
    else if([obj isKindOfClass:[NSNull class]])
        return [self nullToString];
    else{
        return obj;
    }
}
+(NSDictionary *)nullDic:(NSDictionary *)myDic{
    NSArray *keyArr = [myDic allKeys];
    NSMutableDictionary *resDic = [[NSMutableDictionary alloc]init];
    for (int i = 0; i < keyArr.count; i ++)
    {
        id obj = [myDic objectForKey:keyArr[i]];
        obj = [self changeType:obj];
        [resDic setObject:obj forKey:keyArr[i]];
    }
    return resDic;
}

+(NSArray *)nullArr:(NSArray *)myArr
{
    NSMutableArray *resArr = [[NSMutableArray alloc] init];
    for (int i = 0; i < myArr.count; i ++)
    {
        id obj = myArr[i];
        obj = [self changeType:obj];
        [resArr addObject:obj];
    }
    return resArr;
}
//将NSString类型的原路返回

+(NSString *)stringToString:(NSString *)string
{
    return string;
}
//将Null类型的项目转化成@""

+(NSString *)nullToString
{
    return @"";
}
+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString {
    if (jsonString == nil) {
        return nil;
    }
    
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *err;
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData
                                                        options:NSJSONReadingMutableContainers
                                                          error:&err];
    if(err) {
        NSLog(@"json解析失败：%@",err);
        return nil;
    }
    
    return dic;
}

- (NSString *)jsonString {
    NSData *infoJsonData = [NSJSONSerialization dataWithJSONObject:self
                                                           options:NSJSONWritingPrettyPrinted
                                                             error:nil];
    NSString *json = [[NSString alloc] initWithData:infoJsonData encoding:NSUTF8StringEncoding];
    
    return json;
}

- (id)safeObjectForKey:(id<NSCopying>)aKey {
    if (aKey == nil) {
        return nil;
    }
    
    return [self objectForKey:aKey];
}

- (int)intValueForKey:(id)key {
    id obj = [self safeObjectForKey:key];
    
    if ([obj respondsToSelector:@selector(intValue)]) {
        return [obj intValue];
    }
    
    return 0;
}

- (double)doubleValueForKey:(id)key {
    id obj = [self safeObjectForKey:key];
    
    if ([obj respondsToSelector:@selector(doubleValue)]) {
        return [obj doubleValue];
    }
    
    return 0.0;
}

- (float)floatValueForKey:(id)key {
    id obj = [self safeObjectForKey:key];
    
    if ([obj respondsToSelector:@selector(floatValue)]) {
        return [obj floatValue];
    }
    
    return 0.0f;
}

- (NSInteger)integerValueForKey:(id)key {
    id obj = [self safeObjectForKey:key];
    
    if ([obj respondsToSelector:@selector(integerValue)]) {
        return [obj integerValue];
    }
    
    return 0;
}

- (NSString *)stringValueForKey:(id)key {
    id obj = [self safeObjectForKey:key];
    
    if ([obj respondsToSelector:@selector(stringValue)]) {
        return [obj stringValue];
    }
    
    return nil;
}

- (NSDictionary *)dictionaryValueForKey:(id)key {
    id obj = [self safeObjectForKey:key];
    
    if ([obj isKindOfClass:[NSDictionary class]]) {
        return (NSDictionary *)obj;
    }
    
    return nil;
}

- (NSArray *)arrayValueForKey:(id)key {
    id obj = [self safeObjectForKey:key];
    
    if ([obj isKindOfClass:[NSArray class]]) {
        return (NSArray *)obj;
    }
    
    return nil;
}

- (NSNumber *)numberValueForKey:(id)key {
    id obj = [self safeObjectForKey:key];
    
    if ([obj isKindOfClass:[NSNumber class]]) {
        return (NSNumber *)obj;
    }
    
    return nil;
}
@end
