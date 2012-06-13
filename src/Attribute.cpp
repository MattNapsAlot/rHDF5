#ifndef ATTRIBUTE_CPP
#define ATTRIBUTE_CPP

#include <rHDF5.h>

#include <map>
#include <string>
#include <utility>

using namespace std ;
using namespace Rcpp ;

#ifndef H5_NO_NAMESPACE
	using namespace H5;
#endif

string attribute_getName(Attribute* obj) {
    return obj->getName();
}

RCPP_MODULE(attribute){
	class_<Attribute>( "Attribute" ) 

	.constructor()
	.constructor<const hid_t>()

	.method( "close", &Attribute::close )
	.method( "getFileName", &Attribute::getFileName )
	//.method( "getName", &Attribute::getName )
	//.method( "getSpace", &Attribute::getSpace ) Will have to be implemented via helper after DataSpace dependency is resolved.
	.method( "getStorageSize", &Attribute::getStorageSize )
	.method( "getInMemDataSize", &Attribute::getInMemDataSize )
	//.method( "read", &Attribute::read )         Will have to be implemented via helper after DataType dependency is resolved.
	//.method( "write", &Attribute::write )       (Same as above)  
	.method( "fromClass", &Attribute::fromClass )
	.method( "getId", &Attribute::getId )

// Methods implemented through helper functions.
        .method("getName", &attribute_getName)
	;
}

#endif
