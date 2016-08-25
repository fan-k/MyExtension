//
//  FanBlock.h
//  MyExtension
//
//  Created by 樊康鹏 on 16/8/24.
//  Copyright © 2016年 FanKaren. All rights reserved.
//

#ifndef FanBlock_h
#define FanBlock_h

typedef void (^FanErrorBlock)(NSError *error);
typedef void (^FanVoidBlock)(void);

typedef void (^FanNotificationBlock)(NSNotification *notification);

typedef void (^FanBoolBlock)(BOOL result);
typedef void (^FanBoolMsgBlock)(BOOL result, NSString *errorMsg);

typedef void (^FanArrayBlock)(NSArray *resultList);
typedef void (^FanArrayMsgBlock)(NSArray *resultList, NSString *errorMsg);

typedef void (^FanDictionaryBlock)(NSDictionary *resultDict);
typedef void (^FanDictionaryMsgBlock)(NSDictionary *resultDict, NSString *errorMsg);

typedef void (^FanNumberBlock)(NSNumber *resultNumber);
typedef void (^FanNumberMsgBlock)(NSNumber *resultNumber, NSString *errorMsg);

typedef void (^FanIntegerBlock)(NSInteger resultNumber);
typedef void (^FanIntegerMsgBlock)(NSInteger resultNumber, NSString *errorMsg);

typedef void (^FanStringBlock)(NSString *result);
typedef void (^FanStringMsgBlock)(NSString *result, NSString *errorMsg);

typedef void (^FanIdBlock)(id sender);
typedef void (^FanIdMsgBlock)(id result, NSString *errorMsg);
#endif /* FanBlock_h */
