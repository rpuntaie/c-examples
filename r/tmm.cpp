/*
g++ -std=c++20 -fmodules-ts r/tmm.internals.cpp r/tmm.helpers.cpp r/tmm.impl.cpp r/tmm.impl2.cpp r/tmm.cpp r/tmmc.cpp
*/

// // dots in module name are for readability purpose, they have no special meaning
// export module tmm;  // module declaration
// 
// export void f(){}       // export f()
// void g(){}              // but not g()
export module tmm; // primary module interface unit
export import :helpers; // re-export(see below) helpers partition
export void f();
export void g();
class A{};  // not exported
export struct B{// B is attached to module "tool"
    void f(){   // not implicitly inline anymore
        A a;    // can safely use non-exported name
    }
    inline void g(){
        A a;    // oops, uses non-exported name
    }
    inline void h(){
        f();    // fine, f() is not inline
    }
};
/*
export int x{}; // export single declaration
export{         // export multiple declarations
    int y{};
    void f(){};
}
export namespace A{ // export the whole namespace
    void f();
    void g();
}
namespace B{
    export void f();// export a single declaration within a namespace
    void g();
}
namespace{
    export int x;   // error, x has internal linkage
    export void f();// error, f() has internal linkage
}
export class C; // export as incomplete type
class C{};
export C get_c();
*/
