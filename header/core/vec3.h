#ifndef VEC3_H
#define VEC3_H

class vec3 {
  public:
    // init array of x,y,z storing 3d, each coord is a double
    double e[3];

    // default constructor at origion (0,0,0)
    vec3() : e{0,0,0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // x, y, z declaration
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // This overloads the unary negation operator (-). It returns a new vec3 object that represents the negation of the current vector.
    vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]); }
    
    // These overloads provide access to the components of the vector using array-like syntax. The first version is for read-only access, while the second allows for modification.
    double operator[](int i) const { return e[i]; } // read only
    double& operator[](int i) { return e[i]; }      // writes over 

    /*
    Note that operator[] means we are treating our vec3 as a [] which is an array
    so this overload operator will treat this object as an array
    */

    // This overloads the += operator, allowing two vec3 objects to be added together and storing the result in the left operand. It modifies the current object and returns a reference to it.
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    // This overloads the *= operator for scalar multiplication, allowing a vec3 to be scaled by a scalar t.
    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // same as multiplication but does a 1/t division for whole vector, so inverse of vector
    vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    //  returns the length (magnitude) of the vector
    double length() const {
        return std::sqrt(length_squared());
    }

    // returns the dot product of vector with itself
    // gives you a measure of the "size" of the vector without needing to compute the square root, which is computationally more expensive
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    static vec3 random() {
        return vec3(random_double(), random_double(), random_double());
    }

    static vec3 random(double min, double max) {
        return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
    }

    bool near_zero() const {
        // Return true if the vector is close to zero in all dimensions.
        auto s = 1e-8;
        return (std::fabs(e[0]) < s) && (std::fabs(e[1]) < s) && (std::fabs(e[2]) < s);
    }

};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;


// Vector Utility Functions

// This overloads the << operator to enable easy printing of vec3 objects to output streams.
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// This overloads the + operator to allow addition of two vec3 object
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// This overloads the - operator to allow subtraction of two vec3 objects
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// This overloads the * operator for element-wise multiplication of two vec3 objects
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// Allow for multiplication of a vector by a scalar by left hand side
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// Allow for multiplication of a vector by a scalar by right hand side
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

// This overloads the / operator to allow for scalar division of a vector
inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

// get dot product between 2 vectors
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// get cross product between 2 vectors
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// Returns a unit vector (a vector with a length of 1) in the same direction as the input vector
inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

inline vec3 random_unit_vector() {
    while (true) {
        auto p = vec3::random(-1,1);
        auto lensq = p.length_squared();
        // stops underflow and make sure that vector falls within unit circule
        if (1e-160 < lensq && lensq <= 1)
            return p / sqrt(lensq);
    }
}

inline vec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

/*
    v = v∥ +v⊥
    v∥ =(v⋅n)n
    v⊥ = v−(v⋅n)n

    reflected = v⊥ − v∥
    
    ​reflected=v−2(v⋅n)n
*/
inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*dot(v,n)*n;
}

#endif