#ifndef RHDF5_H 
#define RHDF5_H

#define EXPORT_NUMERIC double

#include <RcppCommon.h>

// General includes for H5 class definitions
#include <H5FDpublic.h>
#include <H5public.h>
#include <H5Fpublic.h>
#include <H5Gpublic.h>
#include <H5Rpublic.h>
#include <H5Dpublic.h>
#include <H5Cpp.h>
#include <H5Classes.h>
#include <H5PropList.h>
#include <H5Attribute.h>

// Forward definitions / template magic
#include <rHDF5Forward.h>
#include <Rcpp.h>

// MUST include these declarations after Rcpp.
#include <rHDF5_FileAccPropList.h>
#include <rHDF5_FileCreatPropList.h>
#include <rHDF5_hsize_t.h>
#include <rHDF5_hssize_t.h>
#include <rHDF5_H5F_close_degree_t.h>
#include <rHDF5_H5FD_mem_t.h>
#include <rHDF5_H5F_scope_t.h>
#include <rHDF5_H5G_obj_t.h>
#include <rHDF5_H5R_type_t.h>
#include <rHDF5_FileAccPropList.h>
#include <rHDF5_PropList.h> 
#include <rHDF5_Attribute.h>
#endif
