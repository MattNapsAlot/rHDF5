#include <rHDF5.h>
#include <map>
#include <string>
#include <utility>

using namespace Rcpp ;

#ifndef H5_NO_NAMESPACE
	using namespace H5;
#endif

std::map<string, EXPORT_NUMERIC> filecreatproplist_getVersion(FileCreatPropList* obj) {
    unsigned super;
    unsigned freelist;
    unsigned stab;
    unsigned shhdr;

    map<string, EXPORT_NUMERIC> result;

    obj->getVersion(super, freelist, stab, shhdr);

    result.insert( pair<string, EXPORT_NUMERIC >("super", (EXPORT_NUMERIC) super) );
    result.insert( pair<string, EXPORT_NUMERIC >("freelist", (EXPORT_NUMERIC) freelist) );
    result.insert( pair<string, EXPORT_NUMERIC >("stab", (EXPORT_NUMERIC) stab) );
    result.insert( pair<string, EXPORT_NUMERIC >("shhdr", (EXPORT_NUMERIC) shhdr) );

    return result;
}

std::map<string, EXPORT_NUMERIC> filecreatproplist_getSizes(FileCreatPropList* obj) {
    size_t sizeof_addr;
    size_t sizeof_size;

    map<string, EXPORT_NUMERIC> result;

    obj->getSizes(sizeof_addr, sizeof_size);

    result.insert( pair<string, EXPORT_NUMERIC >("sizeof_addr", (EXPORT_NUMERIC) sizeof_addr) );
    result.insert( pair<string, EXPORT_NUMERIC >("sizeof_size", (EXPORT_NUMERIC) sizeof_size) );

    return result;
}

std::map<string, EXPORT_NUMERIC> filecreatproplist_getSymk(FileCreatPropList* obj) {
    unsigned ik;
    unsigned lk;

    map<string, EXPORT_NUMERIC> result;

    obj->getSymk(ik, lk);

    result.insert( pair<string, EXPORT_NUMERIC >("ik", (EXPORT_NUMERIC) ik) );
    result.insert( pair<string, EXPORT_NUMERIC >("lk", (EXPORT_NUMERIC) lk) );

    return result;
}


RCPP_MODULE(filecreatproplist){
	class_<FileCreatPropList>( "FileCreatPropList" ) 
	
	.constructor()
	.constructor<const hid_t>()
	
	//.method( "getVersion", &FileCreatPropList::getVersion )
	.method( "setUserblock", &FileCreatPropList::setUserblock )
	.method( "getUserblock", &FileCreatPropList::getUserblock )
	//.method( "getSizes", &FileCreatPropList::getSizes )
	.method( "setSizes", &FileCreatPropList::setSizes )
	//.method( "getSymk", &FileCreatPropList::getSymk )
	.method( "setSymk", &FileCreatPropList::setSymk )
	.method( "getIstorek", &FileCreatPropList::getIstorek )
	.method( "setIstorek", &FileCreatPropList::setIstorek )
	.method( "fromClass", &FileCreatPropList::fromClass )

        // Methods implemented through helper functions
        .method( "getVersion", &filecreatproplist_getVersion )
        .method( "getSizes", &filecreatproplist_getSizes )
        .method( "getSymk", &filecreatproplist_getSymk )
        ;

}
