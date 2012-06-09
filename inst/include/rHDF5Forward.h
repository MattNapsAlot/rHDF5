#ifndef RHDF5FORWARD_H
#define RHDF5FORWARD_H

using namespace H5 ;

namespace Rcpp{
        template <> inline SEXP wrap( const hsize_t& ) ;
        template <> inline hsize_t as( SEXP ) ;

        template <> inline SEXP wrap( const hssize_t& ) ;
        template <> inline hssize_t as( SEXP ) ;
	
	template <> inline SEXP wrap( const H5F_close_degree_t& ) ;
	template <> inline H5F_close_degree_t as( SEXP ) ;

	template <> inline SEXP wrap( const H5FD_mem_t& ) ;
	template <> inline H5FD_mem_t as( SEXP ) ;
	
	template <> inline SEXP wrap( const H5F_scope_t& ) ;
        template <> inline H5F_scope_t as( SEXP ) ;

	template <> inline SEXP wrap( const H5G_obj_t& ) ;
        template <> inline H5G_obj_t as( SEXP ) ;
 
	template <> inline SEXP wrap( const H5R_type_t& ) ;
        template <> inline H5R_type_t as( SEXP ) ;

        template <> inline SEXP wrap( const FileAccPropList& );
        template <> inline FileAccPropList as( SEXP );

        template <> inline SEXP wrap( const FileCreatPropList& ) ;
        template <> inline FileCreatPropList as( SEXP ) ;

        template <> inline SEXP wrap( const PropList& ) ;
        template <> inline PropList as( SEXP ) ;
 
        // TODO:  H5::Dataset
                    //DataType
                    //DataSpace
                    //DSetMemXferPropList
                    //H5Object
                    //H5File
                    //Atribute

}

#endif
