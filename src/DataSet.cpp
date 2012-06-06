#ifndef DATASET_CPP
#define DATASET_CPP

#include <rHDF5.h>

using namespace Rcpp ;

RCPP_MODULE(h5dataset) {
	using namespace H5 ;
	class_<DataSet>("DataSet")
	.constructor()
	
	.method( "getId", &DataSet::getId)
	;
}

#endif
