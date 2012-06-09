#include <rHDF5.h>
#include <map>
#include <string>
#include <utility>

using namespace Rcpp ;

#ifndef H5_NO_NAMESPACE
	using namespace H5;
#endif

RCPP_MODULE(proplist){
	class_<PropList>( "PropList" ) 
	
	.constructor()
	.constructor<const hid_t>()
	
	.method( "close", &PropList::close )
        .method( "closeClass", &PropList::closeClass )
        //.method( "copy", &PropList::close )       
        //.method("copyProp", &PropList::copyProp ) Difficulty:  Overloaded 4 ways.  It may be that only one of these makes sense for R, though.
        .method("getClass", &PropList::getClass )
        .method("getClassName", &PropList::getClassName )
        .method("getNumProps", &PropList::getNumProps )
        //.method("getProperty", &PropList::getProperty ) Difficulty:  Overloaded 4 ways.
        //.method("setProperty", &PropList::setProperty ) Difficulty:  Overloaded 4 ways.  
        //.method("getPropSize", &PropList::getPropSize ) Difficulty:  Overloaded 2 ways.
        //.method("isAClass", &PropList::isAClass )
        //.method("propExist", &PropList::propExist ) Difficulty:  Overloaded 2 ways.
        //.method("removeProp", &PropList::removeProp ) Difficulty:  Overloaded 2 ways.
        .method("fromClass", &PropList::fromClass )
        .method("getId", &PropList::getId )
        ;

}
