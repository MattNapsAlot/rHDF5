#ifndef DATASPACE_CPP
#define DATASPACE_CPP

#include <rHDF5.h>

#include <map>
#include <string>
#include <utility>

using namespace std ;
using namespace Rcpp ;

#ifndef H5_NO_NAMESPACE
	using namespace H5;
#endif

RCPP_MODULE(dataspace){
	class_<DataSpace>( "DataSpace" ) 

	.constructor()
	.constructor<const hid_t>()
        // .constructor<const H5S_class_t>()  Needs to be wrapped
        // There is another dataspace constructor, but it uses pointers... 

        // Commented lines below will need helper functions.
	//.method( "copy", &DataSpace::copy )
	//.method( "extentCopy", &DataSpace::extentCopy )
	//.method( "getSelectBounds", &DataSpace::getSelectBounds )
	.method( "getSelectElemNpoints", &DataSpace::getSelectElemNpoints ) 
	//.method( "getSelectElemPointlist", &DataSpace::getSelectElemPointlist )
	//.method( "getSelectHyperBlocklist", &DataSpace::getSelectHyperBlocklist )
	.method( "getSelectHyperNblocks", &DataSpace::getSelectHyperNblocks )      
	.method( "getSelectNpoints", &DataSpace::getSelectNpoints )  
        //.method("getSimpleExtentDims", &dataSpace::getSimpleExtentDims )
	.method( "getSimpleExtentNdims", &DataSpace::getSimpleExtentNdims )
	.method( "getSimpleExtentNpoints", &DataSpace::getSimpleExtentNpoints )
        //.method( "getSimpleExtentType", &DataSpace::getSimpleExtentType ) // H5S_class_t needs to be wrapped.
        .method( "isSimple", &DataSpace::isSimple )
        //.method( "offsetSimple", &DataSpace::offsetSimple )
        .method( "selectAll", &DataSpace::selectAll )
        //.method( "selectElements", &DataSpace::selectElements )
        //.method( "selectHyperslab", &DataSpace::selectHyperslab )
        .method( "selectNone", &DataSpace::selectNone )
        .method( "selectValid", &DataSpace::selectValid )
        .method( "setExtentNone", &DataSpace::setExtentNone )
        //.method( "selectExtentSimple", &DataSpace::selectExtentSimple )
        .method( "fromClass", &DataSpace::fromClass )
        .method( "getId", &DataSpace::getId )

// Methods implemented through helper functions.
	;
}

#endif
