#include <rHDF5.h>
#include <map>
#include <string>
#include <utility>

using namespace Rcpp ;

#ifndef H5_NO_NAMESPACE
	using namespace H5;
#endif

void proplist_copy(PropList* obj, PropList like_plist) 
{
   obj->copy(like_plist);
}

std::map<string, PropList> proplist_copyProp(PropList* obj, PropList dest, PropList src, string name)
{
   std::map<string, PropList> result;  
 
   if (src == NULL) {
     obj->copyProp(dest, name.c_str());
   } else {
     obj->copyProp(dest, src, name.c_str());
   }

    result.insert( pair<string, PropList >("dest", dest) );
    result.insert( pair<string, PropList >("src", src) );

    return(result);
}

string proplist_getProperty(PropList* obj, string name) 
{
   return obj->getProperty(name.c_str());
}

void proplist_setProperty(PropList* obj, string name, string value)
{
   H5std_string tempStr = value.c_str();
   obj->setProperty(name.c_str(), tempStr);
}

size_t proplist_getPropSize(PropList* obj, string name)
{
   return obj->getPropSize(name.c_str());
}

bool proplist_isAClass(PropList* obj, PropList prop_class)
{
   return(obj->isAClass(prop_class));
}

bool proplist_propExist(PropList* obj, string name)
{
   return(obj->propExist(name.c_str()));
}

void proplist_removeProp(PropList* obj, string name)
{
  obj->removeProp(name.c_str());
}


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

        // These were implemented through helper functions.
        .method( "copy", &proplist_copy )
        .method( "copyProp", &proplist_copyProp )
        .method( "getProperty", &proplist_getProperty )
        .method( "setProperty", &proplist_setProperty )
        .method( "getPropSize", &proplist_getPropSize )
        .method( "isAClass", &proplist_isAClass )
        .method( "propExist", &proplist_propExist )
        .method( "removeProp", &proplist_removeProp )
        ;
}
