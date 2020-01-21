//
//  FLEXRuntime+UIKitHelpers.h
//  FLEX
//
//  Created by Tanner Bennett on 12/16/19.
//  Copyright © 2019 Flipboard. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FLEXProperty.h"
#import "FLEXIvar.h"
#import "FLEXMethod.h"
#import "FLEXProtocol.h"

@protocol FLEXRuntimeMetadata <NSObject>

@property (nonatomic, readonly) NSString *name;
/// YES for properties and ivars which surely support editing, NO for all methods.
@property (nonatomic, readonly) BOOL isEditable;
/// NO for ivars, YES for supported methods and properties
@property (nonatomic, readonly) BOOL isCallable;

/// For internal use
@property (nonatomic) id tag;

/// Should return \c nil if not applicable
- (id)currentValueWithTarget:(id)object;
/// Used as the subtitle or description of a property, ivar, or method
- (NSString *)previewWithTarget:(id)object;
/// For methods, a method calling screen. For all else, an object explorer.
- (UIViewController *)viewerWithTarget:(id)object;
/// For methods and protocols, nil. For all else, an a field editor screen.
- (UIViewController *)editorWithTarget:(id)object;
/// Used to determine present which interactions are possible to the user
- (UITableViewCellAccessoryType)suggestedAccessoryTypeWithTarget:(id)object;

@end

// Even if a property is readonly, it still may be editable
// via a setter. Checking isEditable will not reflect that
// unless the property was initialized with a class.
@interface FLEXProperty (UIKitHelpers) <FLEXRuntimeMetadata> @end
@interface FLEXIvar (UIKitHelpers) <FLEXRuntimeMetadata> @end
@interface FLEXMethodBase (UIKitHelpers) <FLEXRuntimeMetadata> @end
@interface FLEXMethod (UIKitHelpers) <FLEXRuntimeMetadata> @end
@interface FLEXProtocol (UIKitHelpers) <FLEXRuntimeMetadata> @end
