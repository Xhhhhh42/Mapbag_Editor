/**
 * Created by Yuchen Xia on 07.11.23.
 * 
 */

#ifndef MAPBAG_EDITOR_USER_INTERFACE_BEZIER_CURVE_H
#define MAPBAG_EDITOR_USER_INTERFACE_BEZIER_CURVE_H


#include <hector_math/types.h>
#include <vector>


namespace mapbag_editor_user_interface
{

inline float factorial( int n ) 
{
    if( n <= 1 )return 1;
    return factorial( n - 1 ) * n;
}


/**
 * 
 * @param points 
 * @return      
 */
inline bool bezierCommon( std::vector<hector_math::Vector2<float>> &points, float t, hector_math::Vector2<float> &point ) 
{
    if( points.size() == 1 ) {
        point = points[0];
        return true;
    }
    hector_math::Vector2<float> p_t( 0, 0 );
    int n = points.size() - 1;

    for( size_t i = 0; i < points.size(); i++ ){
        float C_n_i = factorial( n ) / ( factorial( i ) * factorial( n - i ));
        p_t +=  C_n_i * pow(( 1 - t ), ( n - i )) * pow( t, i ) * points[i];
        //cout<<t<<","<<1-t<<","<<n-i<<","<<pow((1-t),(n-i))<<endl;
    }
    point = p_t;
    return true;
}

} // namespace mapbag_editor_user_interface

#endif // MAPBAG_EDITOR_USER_INTERFACE_BEZIER_CURVE_H



