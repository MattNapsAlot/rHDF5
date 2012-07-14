#ifndef RHDF5_DATASPACE_H
#define RHDF5_DATASPACE_H

#include <map>
#include <string> 
#include <utility>

using namespace std;

namespace Rcpp{

        template <> inline SEXP wrap( const DataSpace& myClass )
        {
            // No STL was actually necessary for this one.
            // Let's not complicate any class more than we have to.
            // The only STL objects we can pass are string, vector/deque/list<primitive> anyway
            hid_t result;

            // Have to do this for every member of the class that is important.
            // In this case, result was the only one that mattered.
            result = myClass.getId();

            return wrap(result);
        }

        template <> inline DataSpace as( SEXP s )
        {
            // Convert s into my ID using as.
            hid_t myID = as<hid_t>(s);

            // Initialize a new class based on the returned members.
            DataSpace result(myID);

            return result;
        }
}

#endif
