//
//  OAuth1Controller.h
//  Simple-OAuth1
//
//  Created by Christian Hansen on 02/12/12.
//  Copyright (c) 2012 Christian-Hansen. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol OAuth1ControllerOptions <NSObject>

- (NSString *_Nonnull)consumerKey;
- (NSString *_Nonnull)consumerSecret;

- (NSString *_Nonnull)requestTokenUrl;
- (NSString *_Nonnull)authorizeUrl;
- (NSString *_Nonnull)accessTokenUrl;

- (NSString *_Nonnull)requestTokenHTTPMethod;
- (NSString *_Nonnull)accessTokenHTTPMethod;

- (NSString *_Nullable)callbackUrl;

- (NSDictionary *_Nonnull)standardParameters;
- (NSDictionary *)allParameters;

@end

@interface BaseOAuth1Options : NSObject <OAuth1ControllerOptions>

@property(nonatomic, copy, nonnull) NSString *consumerKey;
@property(nonatomic, copy, nonnull) NSString *consumerSecret;

@property(nonatomic, copy, nonnull) NSString *requestTokenUrl;
@property(nonatomic, copy, nonnull) NSString *authorizeUrl;
@property(nonatomic, copy, nonnull) NSString *accessTokenUrl;

@property(nonatomic, copy, nonnull) NSString *requestTokenHTTPMethod;
@property(nonatomic, copy, nonnull) NSString *accessTokenHTTPMethod;

@property(nonatomic, copy, nullable) NSString *callbackUrl;

@end

@interface OAuth1Controller : NSObject <UIWebViewDelegate>

- (instancetype)initWithOptions:(id<OAuth1ControllerOptions>)options;

@property(nonatomic, strong, nonnull, readonly) id<OAuth1ControllerOptions>
    options;

- (void)loginWithWebView:(UIWebView *)webWiew
              completion:(void (^)(NSDictionary *oauthTokens,
                                   NSError *error))completion;

- (void)requestAccessToken:(NSString *)oauth_token_secret
                oauthToken:(NSString *)oauth_token
             oauthVerifier:(NSString *)oauth_verifier
                completion:(void (^)(NSError *error,
                                     NSDictionary *responseParams))completion;

@end
