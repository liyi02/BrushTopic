//
//  LJABTestConfigFetchBuild.h
//  Lianjia_Beike_Base
//
//  Created by beike-jiang on 2020/11/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 自定义上报NSUserDefaults key
extern NSString *const LJCustomReporterCloseState;

@interface LJABTestConfigFetchBuild : NSObject

+ (instancetype)builder;

- (void)setup;

@end

NS_ASSUME_NONNULL_END
