#include "glefit.hpp"
#include "ioparser.hpp"
#include "matrix-io.hpp"
#include "linalg.hpp"

using namespace toolbox;

std::istream& operator>> (std::istream& istr, GLEFDir& value)
{
    std::string str;
    istr>>str;
    if      (str=="=")    value=Equal;
    else if (str==">")    value=Greater;
    else if (str=="<")    value=Smaller;
    else istr.clear(std::ios::failbit);
    return istr;
}
    
std::ostream& operator<< (std::ostream& ostr, const GLEFDir& p)
{
    switch (p) 
    {
        case Equal:       ostr<<" = ";  break;
        case Greater:     ostr<<" > ";  break;
        case Smaller:     ostr<<" < ";  break;
    };
    return ostr;
}

std::istream& operator>> (std::istream& istr, GLEFMetric& value)
{
    std::string str;
    istr>>str;
    if      (str=="lin")      value=Linear;
    else if (str=="log")      value=Logarithmic;
    else if (str=="exp")      value=Exponential;
    else istr.clear(std::ios::failbit);
    return istr;
}
    
std::ostream& operator<< (std::ostream& ostr, const GLEFMetric& p)
{
    switch (p) 
    {
        case Linear:       ostr<<" lin ";   break;
        case Logarithmic:  ostr<<" log ";   break;
        case Exponential:  ostr<<" exp ";   break;
    };
    return ostr;
}
    
std::istream& operator>> (std::istream& istr, GLEFPointType& value)
{
    std::string str;
    istr>>str;
    if      (str=="taup2")    value=TauP2;
    else if (str=="tauq2")    value=TauQ2;
    else if (str=="tauh" )    value=TauH;
    else if (str=="kp2"  )    value=KP2;
    else if (str=="kq2"  )    value=KQ2;
    else if (str=="kh"   )    value=KH;
    else if (str=="kw"   )    value=Kw;
    else if (str=="hw"   )    value=Hw;
    else if (str=="honk" )    value=HonK;
    else if (str=="dwq"  )    value=DwQ;
    else if (str=="dwp"  )    value=DwP;
    else if (str=="rdwq" )    value=rDwQ;
    else if (str=="rdwp" )    value=rDwP;
    else if (str=="lfp"  )    value=LFP;
    else if (str=="pi2"  )    value=PI2;
    else if (str=="pi10" )    value=PI10;
    else if (str=="pi100")    value=PI100;
    else if (str=="cqqdt")    value=CqqDT;
    else if (str=="cppdt")    value=CppDT;
    else if (str=="cqq"  )    value=Cqq;
    else if (str=="cpp"  )    value=Cpp;
    else istr.clear(std::ios::failbit);
    return istr;
}
    
std::ostream& operator<< (std::ostream& ostr, const GLEFPointType& p)
{
    switch (p) 
    {
        case TauP2:    ostr<<" taup2 ";    break;
        case TauQ2:    ostr<<" tauq2 ";    break;
        case TauH:     ostr<<" tauh  ";    break;
        case KP2:      ostr<<"  kp2  ";    break;
        case KQ2:      ostr<<"  kq2  ";    break;
        case KH:       ostr<<"  kh   ";    break;
        case Kw:       ostr<<"  kw   ";    break;
        case Hw:       ostr<<"  hw   ";    break;
        case HonK:     ostr<<" honk  ";    break;
        case DwQ:      ostr<<"  dwq  ";    break;
        case DwP:      ostr<<"  dwp  ";    break;
        case rDwQ:     ostr<<" rdwq  ";    break;
        case rDwP:     ostr<<" rdwp  ";    break;
        case LFP:      ostr<<"  lfp  ";    break;
        case PI2:      ostr<<"  pi2  ";    break;
        case PI10:     ostr<<"  pi10 ";    break;
        case PI100:    ostr<<" pi100 ";    break;
        case CppDT:    ostr<<" cppdt ";    break;
        case CqqDT:    ostr<<" cqqdt ";    break;
        case Cpp:      ostr<<"  cpp  ";    break;
        case Cqq:      ostr<<"  cqq  ";    break;
    };
    return ostr;
}
    
std::istream& operator>> (std::istream& istr, GLEFGlobType& value)
{
    std::string str;
    istr>>str;
    if      (str=="gzero"  )        value=GZero;
    else if (str=="ginf"   )        value=GInf;
    else if (str=="tzero"  )        value=TZero;
    else if (str=="tinf"   )        value=TInf;
    else if (str=="aratio" )        value=ARatio;
    else if (str=="cratio" )        value=CRatio;
    else if (str=="pqratio")        value=PQRatio; 
    else if (str=="aespread" )      value=AEigvSpread;
    else if (str=="aecenter" )      value=AEigvCenter;
    else if (str=="aeweight" )      value=AEigvWeight;
    else if (str=="deltaspread" )   value=DeltaSpread;
    else if (str=="deltaweight" )   value=DeltaWeight;
    else istr.clear(std::ios::failbit);
    return istr;
}
    
std::ostream& operator<< (std::ostream& ostr, const GLEFGlobType& p)
{
    switch (p) 
    {
        case GZero:        ostr<<" gzero     ";    break;
        case GInf:         ostr<<" ginf      ";    break;
        case TZero:        ostr<<" tzero     ";    break;
        case TInf:         ostr<<" tinf      ";    break;
        case ARatio:       ostr<<" aratio    ";    break;
        case CRatio:       ostr<<" cratio    ";    break;
        case PQRatio:      ostr<<" pqratio   ";    break;
        case AEigvSpread:  ostr<<" aespread  ";    break;
        case AEigvCenter:  ostr<<" aecenter  ";    break;
        case AEigvWeight:  ostr<<" aeweight  ";    break;
        case DeltaSpread:  ostr<<" deltaspread ";  break;
        case DeltaWeight:  ostr<<" deltaweight ";  break;

    };
    
    return ostr;
}

std::istream& operator>> (std::istream& istr, GLEFSearchMode& value)
{
    std::string str;
    istr>>str;
    if      (str=="annealing" )     value=Annealing;
    else if (str=="simplex"   )     value=Simplex;
    else if (str=="powell"    )     value=Powell;
    else istr.clear(std::ios::failbit);
    return istr;
}
    
std::ostream& operator<< (std::ostream& ostr, const GLEFSearchMode& p)
{
    switch (p) 
    {
        case Annealing:   ostr<<" annealing ";    break;
        case Simplex:     ostr<<"  simplex  ";    break;
        case Powell:      ostr<<"  powell   ";    break;
    };
    return ostr;
}
    
std::istream& operator>> (std::istream& istr, GLEFParStyleA& value)
{
    std::string str;
    istr>>str;
    if      (str=="realonly"   )        value=ARealOnly;
    else if (str=="full"       )        value=AFull;
    else if (str=="complex"    )        value=AComplex;
    else if (str=="positive"   )        value=APositive;
    else if (str=="preal"      )        value=APReal;
    else if (str=="delta"      )        value=ADelta;
    else if (str=="pgeneral"   )        value=APGeneral;
    else istr.clear(std::ios::failbit);
    return istr;
}
    
std::ostream& operator<< (std::ostream& ostr, const GLEFParStyleA& p)
{
    switch (p) 
    {
        case ARealOnly:      ostr<<" realonly ";    break;
        case AFull:          ostr<<"    full  ";    break;
        case AComplex:       ostr<<" complex  ";    break;
        case APositive:      ostr<<" positive ";    break;
        case APReal:         ostr<<"   preal  ";    break;
        case ADelta:         ostr<<"   pdelta ";    break;
        case APGeneral:      ostr<<" pgeneral ";    break;
    };
    return ostr;
}
    
std::istream& operator>> (std::istream& istr, GLEFParStyleC& value)
{
    std::string str;
    istr>>str;
    if      (str=="identity" )     value=COne;       
    else if (str=="positive" )     value=CPositive;
    else if (str=="indirect" )     value=CIndirect;
    else if (str=="delta"    )     value=CDelta;
    else if (str=="bdiagonal")     value=CBDiagonal;
    else istr.clear(std::ios::failbit);
    return istr;
}
    
    
std::ostream& operator<< (std::ostream& ostr, const GLEFParStyleC& p)
{
    switch (p) 
    {
        case COne:          ostr<<" identity  ";    break;
        case CPositive:     ostr<<" positive  ";    break;
        case CIndirect:     ostr<<" indirect  ";    break;
        case CBDiagonal:    ostr<<" bdiagonal ";    break;
        case CDelta:        ostr<<"   delta   ";    break;
    };
    return ostr;
}

/* TO BE REMOVED SOON...
namespace toolbox {
    template<> inline bool toolbox::IField<GLEFDir>::operator<<(std::istream& istr)
    {
        std::string str;
        istr>>str;
        if      (str=="=")    value=Equal;
        else if (str==">")    value=Greater;
        else if (str=="<")    value=Smaller;
        else return false; 
        return true;
    }
    
    std::ostream& operator<< (std::ostream& ostr, const GLEFDir& p)
    {
        switch (p) 
        {
        case Equal:       ostr<<" = ";  break;
        case Greater:     ostr<<" > ";  break;
        case Smaller:     ostr<<" < ";  break;
        };
        return ostr;
    }

    template<> inline bool toolbox::IField<GLEFMetric>::operator<<(std::istream& istr)
    {
        std::string str;
        istr>>str;
        if      (str=="lin")      value=Linear;
        else if (str=="log")      value=Logarithmic;
        else if (str=="exp")      value=Exponential;
        else return false; 
        return true;
    }
    
    std::ostream& operator<< (std::ostream& ostr, const GLEFMetric& p)
    {
        switch (p) 
        {
        case Linear:       ostr<<" lin ";   break;
        case Logarithmic:  ostr<<" log ";   break;
        case Exponential:  ostr<<" exp ";   break;
        };
        return ostr;
    }
    
    template<> inline bool toolbox::IField<GLEFPointType>::operator<<(std::istream& istr)
    {
        std::string str;
        istr>>str;
        if      (str=="taup2")    value=TauP2;
        else if (str=="tauq2")    value=TauQ2;
        else if (str=="tauh" )    value=TauH;
        else if (str=="kw"   )    value=Kw;
        else if (str=="hw"   )    value=Hw;
        else if (str=="cqq"  )    value=Cqq;
        else if (str=="cpp"  )    value=Cpp;
        else return false; 
        return true;
    }
    
    std::ostream& operator<< (std::ostream& ostr, const GLEFPointType& p)
    {
        switch (p) 
        {
            case TauP2:    ostr<<" taup2 ";    break;
            case TauQ2:    ostr<<" tauq2 ";    break;
            case TauH:     ostr<<" tauh  ";    break;
            case Kw:       ostr<<"  kw   ";    break;
            case Hw:       ostr<<"  hw   ";    break;
            case Cpp:      ostr<<"  cpp  ";    break;
            case Cqq:      ostr<<"  cqq  ";    break;
        };
        return ostr;
    }
    
    template<> inline bool toolbox::IField<GLEFGlobType>::operator<<(std::istream& istr)
    {
        std::string str;
        istr>>str;
        if      (str=="gzero"  )        value=GZero;
        else if (str=="ginf"   )        value=GInf;
        else if (str=="tzero"  )        value=TZero;
        else if (str=="tinf"   )        value=TInf;
        else if (str=="aratio" )        value=ARatio;
        else if (str=="cratio" )        value=CRatio;
        else if (str=="pqratio")        value=PQRatio; 
        else return false; 
        return true;
    }
    
    std::ostream& operator<< (std::ostream& ostr, const GLEFGlobType& p)
    {
        switch (p) 
        {
            case GZero:    ostr<<" gzero   ";    break;
            case GInf:     ostr<<" ginf    ";    break;
            case TZero:    ostr<<" tzero   ";    break;
            case TInf:     ostr<<" tinf    ";    break;
            case ARatio:   ostr<<" aratio  ";    break;
            case CRatio:   ostr<<" cratio  ";    break;
            case PQRatio: ostr<<" pqratio ";    break;
        };
        return ostr;
    }
    
    template<> inline bool toolbox::IField<GLEFSearchMode>::operator<<(std::istream& istr)
    {
        std::string str;
        istr>>str;
        if      (str=="annealing" )     value=Annealing;
        else if (str=="simplex"   )     value=Simplex;
        else if (str=="powell"    )     value=Powell;
        else return false; 
        return true;
    }
    
    std::ostream& operator<< (std::ostream& ostr, const GLEFSearchMode& p)
    {
        switch (p) 
        {
        case Annealing:   ostr<<" annealing ";    break;
        case Simplex:     ostr<<"  simplex  ";    break;
        case Powell:      ostr<<"  powell   ";    break;
        };
        return ostr;
    }
    
    template<> inline bool toolbox::IField<GLEFParStyleA>::operator<<(std::istream& istr)
    {
        std::string str;
        istr>>str;
        if      (str=="realonly"   )        value=ARealOnly;
        else if (str=="full"       )        value=AFull;
        else if (str=="complex"    )        value=AComplex;
        else if (str=="positive"   )        value=APositive;
        else if (str=="preal"      )        value=APReal;
        else if (str=="pgeneral"   )        value=APGeneral;
        else return false; 
        return true;
    }
    
    std::ostream& operator<< (std::ostream& ostr, const GLEFParStyleA& p)
    {
        switch (p) 
        {
            case ARealOnly:      ostr<<" realonly ";    break;
            case AFull:          ostr<<"    full  ";    break;
            case AComplex:       ostr<<" complex  ";    break;
            case APositive:      ostr<<" positive ";    break;
            case APReal:         ostr<<"   preal  ";    break;
            case APGeneral:      ostr<<" pgeneral ";    break;
        };
        return ostr;
    }
    
    template<> inline bool toolbox::IField<GLEFParStyleC>::operator<<(std::istream& istr)
    {
        std::string str;
        istr>>str;
        if      (str=="identity" )     value=COne;       
        else if (str=="positive" )     value=CPositive;
        else if (str=="indirect" )     value=CIndirect;
        else if (str=="bdiagonal")     value=CBDiagonal;
        else return false;
        return true;
    }
    
    
    std::ostream& operator<< (std::ostream& ostr, const GLEFParStyleC& p)
    {
        switch (p) 
        {
            case COne:          ostr<<" identity  ";    break;
            case CPositive:     ostr<<" positive  ";    break;
            case CIndirect:     ostr<<" indirect  ";    break;
            case CBDiagonal:    ostr<<" bdiagonal ";    break;
        };
        return ostr;
    }
};
*/

std::istream& operator>> (std::istream& istr, GLEFValue& p)
{ istr>>p.dir>>p.y>>p.w>>p.metric>>p.e;  return istr;}
std::ostream& operator<< (std::ostream& ostr, const GLEFValue& p)
{ ostr<<" "<<p.dir<<" "<<p.y<<" "<<p.w<<" "<<" "<<p.metric<<" "<<p.e<<" ";  return ostr;}

std::istream& operator>> (std::istream& istr, GLEFPoint& p)
{ 
    IOMap iom;
    iom.insert(p.x, "frequency", 1.0);
    iom.insert(p.values, "values");
    istr>>iom;  
    return istr;
}
std::ostream& operator<< (std::ostream& ostr, const GLEFPoint& p)
{ 
    IOMap iom;
    iom.insert(p.x, "frequency");
    iom.insert(p.values, "values");
    ostr<<iom;
    return ostr;
}

std::istream& operator>> (std::istream& istr, GLEFSearchOptions& op)
{
    IOMap iom;
    iom.insert(op.mode, "mode", Annealing);
    iom.insert(op.steps, "steps", (unsigned long) 1000);
    iom.insert(op.nlinesrc, "linesearch", (unsigned long) 3);
    iom.insert(op.adapt_mult, "adapt_mult", 1.0);
    iom.insert(op.ti, "temp_init", 1.);
    iom.insert(op.tf, "temp_final", 1e-3);
    iom.insert(op.rand, "randomize", -1.);
    iom.insert(op.tol, "tolerance", 1e-5);
    iom.insert(op.step, "stepsize", 1.);
    istr>>iom;
    return istr;
}

std::ostream& operator<< (std::ostream& ostr, const GLEFSearchOptions& op)
{
    ostr<<"mode          "<<op.mode       <<"\n";
    ostr<<"steps         "<<op.steps      <<"\n";
    ostr<<"adapt_mult    "<<op.adapt_mult <<"\n";
    ostr<<"temp_init     "<<op.ti         <<"\n";
    ostr<<"temp_final    "<<op.tf         <<"\n";
    ostr<<"tolerance     "<<op.tol        <<"\n";
    ostr<<"randomize     "<<op.rand       <<"\n";
    ostr<<"stepsize      "<<op.step     <<"\n";
    ostr<<"linesearch    "<<op.nlinesrc <<"\n";  
    return ostr;
}

std::istream& operator>> (std::istream& istr, GLEFParOptions& op)
{
    IOMap iom;
    iom.insert(op.ns, "ns",(unsigned long) 1);
    iom.insert(op.deltat, "finite-dt",0.0);
    iom.insert(op.pstyleC, "cstyle", CIndirect);
    iom.insert(op.pstyleA, "astyle", APReal);
    istr>>iom;
    return istr;
}

std::ostream& operator<< (std::ostream& ostr, const GLEFParOptions& op)
{
    ostr<<" ns        "<<op.ns         <<"\n";
    ostr<<" finite-dt "<<op.deltat     <<"\n";
    ostr<<" astyle    "<<op.pstyleA    <<"\n";
    ostr<<" cstyle    "<<op.pstyleC    <<"\n";
    return ostr;
}

std::ostream& operator<< (std::ostream& ostr, const GLEFFitOptions& op)
{

    ostr<<" points  "<<op.points   <<"\n";
    ostr<<" pnorm   "<<op.pexp     <<"\n";
    ostr<<" pweight "<<op.pweights <<"\n";
    ostr<<" global  "<<op.globs    <<"\n";
    return ostr;
} 

std::istream& operator>> (std::istream& istr, GLEFFitOptions& op)
{ 
    IOMap iom;
    
    iom.insert(op.points, "points");
    iom.insert(op.pexp, "pnorm");
    iom.insert(op.pweights, "pweight");
    iom.insert(op.globs,"global");
    istr >> iom;
    return istr;
}

/***********************************************************************************
 >>                     RESPONSE AND FDT FITTING CLASS                            <<
 let the system have n additional momenta. we parametrize the whole A, including the
 'external rim' so as to insure it has eigenvalues with positive real part. in oder
 to make so, we write A as the sum of a symmetric (P) and  antisymmetric (Q) parts, 
 A=P+Q. We then consider the eigenvalues of P and Q. Q is definite positive, so we 
 have n real eigenvalues to change. P is antisymmetric, so its eigenvalues are either 
 zero or imaginary, in conjugate pairs, so it needs n/2 positive reals 
 [integer division assumed]. 
 BEWARE: if we set gamma=0, then the number of DOF is reduces, because the first row/col
 of A must be antisymmetric, so the search range for Q is reduced from n+1 to n.
 then, we need to put both P and Q in arbitrary basis. we build orthogonal matrices 
 as O=e^-J, where J is an antisymmetric matrix, which has n(n-1)/2 degrees of freedom.
 for C we have the outer rim (chi,c) amounting to n terms [chi is fixed to give correct
 FDT in w->0 limit], while the bulk C is fixed to identity, and doesn't count at all.
************************************************************************************/
/***********************************************************************************
                   PARAMETERIZATION OF THE RESPONSE MATRICES
 >> Ap <<
 EIGENVALUES OF A: Let n be the number of additional degrees of freedom. If so, we need 
 to know n eigenvalues of A, which may be real or complex. In order to compute them smoothly,
 this is what one can do: 
 + start from n numbers (which are the searched parameters) x_i
 + take the even terms (x_0, x_2....) and compute rho_i=exp(x_(2i))
 + compute sin(2 Pi x_(2i+1)). If it is positive, then (just one of all the possible continuous & invertible mappings)
    a_2i=rho_i exp(-tan(2 Pi x_(2i+1)))
    a_2i+1=rho_i exp(-tan(2 Pi x_(2i+1)))
   else, a_2i=rho_i exp(I x_2i+1), a_2i+1=rho_i exp(-I x_2i+1),
 We then have one parameter for a_pp (the friction), and 2n parameters, on a linear scale, 
 for a_p and \bar{a}_p. 
 If mode A is positive, then we enforce a positive-definite A.
 this means we take Ap=QQ^T+P, where
 Q=(a0 a1 a2 a3...   and   P=(0 c1 c2 ...
    0 b1 0 0 0...)           -c1 0 d1 ....)
 we can compute this from the same set of parameters we would get for reduced A, since 
 QQ^T=(ao^2+a1^2+...  a1b1 a2b2....
       a1b1    b1^2 ....        )
 so we can take b_i and d_i from the eigenvalues, and compute the values to get the 
 desired A. one must enforce 
  we take a1,a2.... so that a0^2+a1^2+a2^2...=app (i.e. we enforce this at every step), then recompute
 a_i<-sqrt((a_pp-a0^2)/sum a_i^2)*a_i
 indeed, it is better to parameterize the symmetric and antisymmetric combinations of a_p and \bar{a}_p,\
 even better, in form of modulus plus coordinates
 so, the number of parameters needed for A is the same as for the 'reduced' mode plus one (a0^2!)
 if gamma is fixed and different to zero, we have one less parameter. if it is equal to zero,
 then all the symmetric part of a_p must be zero as well
 
 >> Cp <<
 if mode is identical, then Cp is a diagonal matrix with a single DOF
 if mode is minimal, then we want a matrix of the form
 Cp=(cpp, c1, c2, ....
     c1, d, 0, 0......)
 where d is fixed at 2 cp^2/cpp to ensure that C_p is positive-definite. so, n+1 parameters
 here.
 if mode is positive, then in fact we parameterize Cp=QQ^T, and choose Q in order to get
 the proper Cp. in fact, we take the same parameters as minimal, and increment them with
 a triangular matrix b_ij. we want then to have kpp=sqrt(cpp), k_i=c_i/kpp, fij=kpp bij
 Q=(kpp, 0, .....
    k1,  f11 0
    k2,  f21, f22, 0)
 if mode is indirect, we instead fit B_p as a triangular matrix, with positive elements 
 on the diagonal.
 
************************************************************************************/
double dot(const std::valarray<double>& a, const std::valarray<double>& b)
{ double r=0.; for (int i=0; i<a.size(); ++i) r+=a[i]*b[i]; }

unsigned long npars(const GLEFParOptions& ops)
{
    unsigned long rnp=0, n=ops.ns;
    
    switch (ops.pstyleA)
    {
        case ARealOnly: 
            rnp++;      //global scale factor
            rnp++;      //app
            rnp++;      //eta
            rnp+=n;     //eigenvalues of A, as successive decrements
            rnp+=2*n;   //frame vectors
            break;
        case AComplex:
            if (n%2!=0) ERROR("Must have even number of DOF to use complex eigenvalues");
            rnp++;      //global scale factor
            rnp++;      //app
            rnp++;      //eta
            rnp+=n;     //eigenvalues of A (half for moduli, half for phases)
            rnp+=2*n;   //frame vectors
            break;
        case AFull:
            rnp=(ops.ns+1)*(ops.ns+1);
            break;
        case APositive:
            rnp++;      //global scale factor
            rnp++;      //app (also sets the scale of border elements in symmetric part
            rnp+=((n+1)*(n+2))/2-1;  //triangular matrix, square for pos-def
            rnp+=((n+1)*n)/2;  //antisymmetric part of the matrix
            break;
        //!FITTING MODES DESCRIBED IN THE PAPER!
        case APReal:
            rnp++;   //global scale
            rnp++;   //qpp
            rnp+=2*n; //q frame & q diagonal
            rnp+=n; //asymmetric frame
            break;
        case APGeneral:
            rnp++;   //global scale
            rnp++;   //qpp
            rnp+=2*n; //q frame & q diagonal
            rnp+=n*(n+1)/2; //asymmetric triangle
            break;
        case ADelta:
            rnp++;   //global scale
            rnp++;   //qpp
            rnp+=(n/2)*3; //elements of the n/2 delta thermostats 
            break;
    }
    

    switch (ops.pstyleC)
    {
    case COne:
        break;
    case CPositive:
        rnp+=n;  //cp
        rnp+=n*(n+1)/2;  //C as cholesky dec.
        break;
    case CIndirect:
        rnp++; //cpp, global scale 
        rnp+=(n+2)*(n+1)/2; //compute C from B
        break;
    case CBDiagonal:
        rnp++; //cpp, global scale 
        rnp+=(n+1); //B is diagonal...
        break;
    case CDelta:
        rnp++; //cpp, global scale 
        rnp+=(n/2); //temperatures of the n/2 deltas
        break;
    }
    return rnp;
}


#define _gle_ascale 1
void GLEFError::pars2AC()
{
    unsigned long n=opar.ns;
    unsigned long k=0, i;
    A.resize(n+1,n+1);  A*=0.; C=A; 
#if GLE_DEBUG>1
    std::cerr<<" **        ENTERING pars2AC()       ** \n"
            <<" parameters: "<<p;
#endif
    
    //get the "physical constraints", either from pars array or from fixed options
    /*
    double gzero, ginf, tzero, tinf, aratio, cratio, qpratio;
    double app, cpp;
    {
        if (ops.fixGZero<0)   gzero=exp(p[k++]); 
        else gzero=ops.fixGZero;
        if (ops.fixGInf<0)    ginf=exp(p[k++]);
        else ginf=ops.fixGInf;
        if (ops.fixTZero<0)   tzero=exp(p[k++]);
        else tzero=ops.fixTZero;
        if (ops.fixTInf<0)    tinf=exp(p[k++]);
        else tinf=ops.fixTInf;
        if (ops.fixARatio<0)  { if (ops.pstyleA==APositive) aratio=exp(-(p[k]*p[k++])); else aratio=exp(p[k++]); }
        else aratio=ops.fixARatio;
        if (ops.fixCRatio<0)  cratio=exp(p[k++]);
        else cratio=ops.fixCRatio;
        if (ops.fixQPRatio<0) qpratio=exp(p[k++]); 
        else qpratio=ops.fixQPRatio;
    }
    */
    
    //"pieces" of Ap
    double app;
    std::valarray<double> ap(n), bap(n);
    FMatrix<double> lA(n,n);
    ap=bap=app=0.; lA*=0.;
    if (opar.pstyleA==ARealOnly)
    {
        double ascale=exp(p[k++]), eta;  
        std::valarray<double> rek(n), reg(n), rep(n);
        app=exp(p[k++]); eta=exp(-p[k]*p[k++]); //eta must be <=1
        app*=ascale;
        rek[0]=exp(-p[k++]);  for(int i=1; i<n; ++i) rek[i]=exp(-p[k]*p[k++]);
        for(int i=0; i<n; ++i) reg[i]=ascale*exp(p[k++]);
        
        lA(0,0)=ascale*rek[0]; for(int i=1; i<n; ++i) lA(i,i)=lA(i-1,i-1)*rek[i];
        rep[0]=(app-reg[0])*lA(0,0);  for(int i=1; i<n; ++i) rep[i]=(reg[i-1]-reg[i])*lA(i,i);
        
        for(int i=0; i<n; ++i) ap[i]=p[k++];
        
        //computes actual value of eta, and correct reg and lA to obtain the desired value
        double aceta=0.; 
        for (int i=0; i<n; i++) aceta+=pow(ap[i]+rep[i]/ap[i],2.)/lA(i,i); aceta*=1./(4.*app);
        lA*=aceta/eta; //rep*=aceta/eta;
        
        aceta=0.; for (int i=0; i<n; i++) aceta+=pow(ap[i]+rep[i]/ap[i],2.)/lA(i,i); aceta*=1./(4.*app);
        
        //now translate everything into ap and bap
        for(int i=0; i<n; ++i) bap[i]=rep[i]/ap[i];
    }
    else if (opar.pstyleA==AComplex)
    {
        double ascale=exp(p[k++]), eta;
        std::valarray<double> rek(n/2), rer(n/2), ret(n/2), reg(n/2), rep(n/2), req(n/2), repi(n/2), reti(n/2);
        app=exp(p[k++]); eta=exp(-p[k]*p[k++]); //eta must be <=1
        app*=ascale;
        rek[0]=exp(-p[k++]);  for(int i=1; i<n/2; ++i) rek[i]=exp(-p[k]*p[k++]);
        rer[0]=ascale*rek[0]; for(int i=1; i<n/2; ++i) rer[i]=rer[i-1]*rek[i]; 
        for(int i=0; i<n/2; ++i) ret[i]=p[k++]; //just angles, maybe one can do better...

        for(int i=0; i<n/2; ++i) reg[i]=ascale*exp(p[k++]);
        for(int i=0; i<n/2; ++i) reti[i]=p[k++];
        for(int i=0; i<n/2; ++i) lA(2*i,2*i)=lA(2*i+1,2*i+1)=rer[i]*cos(ret[i]);
        for(int i=0; i<n/2; ++i) lA(2*i,2*i+1)=-(lA(2*i+1,2*i)=rer[i]*sin(ret[i]));
        
        for(int i=0; i<n/2; ++i) 
            repi[i]=((i==0?app:reg[i-1])-reg[i])*rer[i]/cos(ret[i]+reti[i]);
        for(int i=0; i<n/2; ++i) { rep[i]=repi[i]*cos(reti[i]); req[i]=repi[i]*sin(reti[i]); }
        for(int i=0; i<n; ++i) ap[i]=p[k++];
        for(int i=0; i<n/2; ++i) {
            bap[2*i]=(ap[2*i]*rep[i]-ap[2*i+1]*req[i])/(ap[2*i]*ap[2*i]+ap[2*i+1]*ap[2*i+1]);  
            bap[2*i+1]=(ap[2*i]*req[i]+ap[2*i+1]*rep[i])/(ap[2*i]*ap[2*i]+ap[2*i+1]*ap[2*i+1]);  
        } //computes bap, which will also serve to correct eta
        
        //computes actual value of eta, and correct reg and lA to obtain the desired value
        double aceta=0.; 
        for (int i=0; i<n; i++) aceta+=(ap[i]+bap[i])*(ap[i]+bap[i])/lA(i,i); aceta*=1./(4.*app);
        lA*=aceta/eta; rer*=aceta/eta;

        aceta=0.; for (int i=0; i<n; i++) aceta+=pow(ap[i]+bap[i],2.)/lA(i,i); aceta*=1./(4.*app);
        
        for (int i=0; i<n/2; i++) (*seva)<<rer[i]<<" "; 
        for (int i=0; i<n/2; i++) (*seva)<<ret[i]<<" "; 
        (*seva)<<std::endl;
    }
    else if (opar.pstyleA==AFull)
    {
        app=p[k++];
        for (int i=0; i<n; i++) ap[i]=p[k++];
        for (int i=0; i<n; i++) bap[i]=p[k++];
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) lA(i,j)=p[k++]; 
    }
    else if (opar.pstyleA==AFull)
    {
        app=p[k++];
        for (int i=0; i<n; i++) ap[i]=p[k++];
        for (int i=0; i<n; i++) bap[i]=p[k++];
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) lA(i,j)=p[k++]; 
    }
    else if (opar.pstyleA==APositive)
    {
        double ascale=exp(p[k++]);
        app=exp(p[k++]); 
        
        FMatrix<double> Q(n+1,n+1), P(n+1,n+1), QQT, T1;
        
        Q*=0.; P*=0.;
        app*=ascale;
        
        Q(0,0)=sqrt(app/ascale);
        for(int i=1; i<n+1; ++i) Q(i,i)=exp(p[k++]);
        for(int i=1; i<n+1; ++i) for(int j=0; j<i; ++j) Q(i,j)=p[k++];
        for(int i=1; i<n+1; ++i) for(int j=0; j<i; ++j) P(j,i)=-(P(i,j)=p[k++]);
        transpose(Q,T1);
        mult(Q,T1,QQT); P+=QQT; P*=ascale;
        
        for (int i=0; i<n; i++) ap[i]=P(0,i+1);
        for (int i=0; i<n; i++) bap[i]=P(i+1,0);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) lA(i,j)=P(i+1,j+1);
    }
    else if (opar.pstyleA==APReal)
    {
        double ascale=exp(p[k++]);
        app=exp(p[k++]); 
        
        FMatrix<double> Q(n+1,n+1), P(n+1,n+1), QQT, T1;
        Q*=0.; P*=0.;
        app*=ascale;
        
        Q(0,0)=sqrt(app/ascale);
        for(int i=1; i<n+1; ++i) Q(i,i)=exp(p[k++]);
        for(int i=1; i<n+1; ++i) Q(0,i)=p[k++];
        for(int i=1; i<n+1; ++i) P(i,0)+=-(P(0,i)=p[k++]);
        transpose(Q,T1);
        mult(Q,T1,QQT); P+=QQT; P*=ascale;
        
        app=P(0,0);
        for (int i=0; i<n; i++) ap[i]=P(0,i+1);
        for (int i=0; i<n; i++) bap[i]=P(i+1,0);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) lA(i,j)=P(i+1,j+1);
    }
    else if (opar.pstyleA==ADelta)
    {
        double ascale=exp(p[k++]);
        app=exp(p[k++]); 
     
        app*=ascale;
        ap=0.; bap=0.; lA*=0.;
        for (int i=0; i<n/2; i++) ap[i*2]=sqrt(exp(p[k++])/(2*constant::pi));
        bap=-ap; ap*=ascale; bap*=ascale; 
#define DELTA_SMALL 1e-50
        for (int i=0; i<n/2; i++)  {  lA(2*i,2*i)=exp(p[k++]); lA(2*i+1,2*i+1)=DELTA_SMALL; lA(2*i+1,2*i)=-(lA(2*i,2*i+1)=exp(p[k++])); }
        lA*=ascale;
    }
    else if (opar.pstyleA==APGeneral)
    {
        double ascale=exp(p[k++]);
        app=exp(p[k++]); 
        
        FMatrix<double> Q(n+1,n+1), P(n+1,n+1), QQT, T1;
        Q*=0.; P*=0.;
        app*=ascale;
        
        Q(0,0)=sqrt(app/ascale);
        for(int i=1; i<n+1; ++i) Q(i,i)=exp(p[k++]);
        for(int i=1; i<n+1; ++i) Q(0,i)=p[k++];
        for(int i=0; i<n+1; ++i) for(int j=i+1; j<n+1; ++j) P(j,i)+=-(P(i,j)=p[k++]);
        transpose(Q,T1);
        mult(Q,T1,QQT); P+=QQT; P*=ascale;
        
        app=P(0,0);
        for (int i=0; i<n; i++) ap[i]=P(0,i+1);
        for (int i=0; i<n; i++) bap[i]=P(i+1,0);
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) lA(i,j)=P(i+1,j+1);
    }    
    //puts the pieces of A together
    A(0,0)=app;
    for (int i=0; i<n; i++)  for (int j=0; j<n; j++) A(i+1,j+1)=lA(i,j);
    for (int i=0; i<n; i++) A(0,i+1)=ap[i];
    for (int i=0; i<n; i++) A(i+1,0)=bap[i];
    
    ////// >>>>> COMPUTE C <<<<<<<<<
    FMatrix<double> lC(n,n);
    std::valarray<double> cp(n);
    double cpp=(opar.pstyleC==COne?1.:exp(p[k++]));
    if (opar.pstyleC==COne)
    {  cp=0; for (int i=0; i<n; i++) lC(i,i)=cpp; }
    else if (opar.pstyleC==CIndirect)
    {
        GLEABC iABC; FMatrix<double> B(n+1,n+1),BBT,T1;
        for (int i=0; i<n+1; i++) B(i,i)=exp(p[k++]);
        for (int i=1; i<n+1; i++) for (int j=0; j<i; j++) B(i,j)=p[k++];
        transpose(B,T1); mult(B,T1,BBT);
        iABC.set_A(A); iABC.set_BBT(BBT);
        iABC.get_C(T1); T1*=cpp/T1(0,0);
        for (int i=0; i<n; i++) cp[i]=T1(0,i+1);
        for (int i=0; i<n; i++) for (int j=0; j<n;j++) lC(i,j)=T1(i+1,j+1);
    }
    else if (opar.pstyleC==CBDiagonal)
    {
        GLEABC iABC; FMatrix<double> B(n+1,n+1),BBT,T1;
        B*=0.;
        for (int i=0; i<n+1; i++) B(i,i)=exp(p[k++]);
        transpose(B,T1); mult(B,T1,BBT);
        iABC.set_A(A); iABC.set_BBT(BBT);
        iABC.get_C(T1); T1*=cpp/T1(0,0);
        for (int i=0; i<n; i++) cp[i]=T1(0,i+1);
        for (int i=0; i<n; i++) for (int j=0; j<n;j++) lC(i,j)=T1(i+1,j+1);
    }
    else if (opar.pstyleC==CPositive)
    {
        for (int i=1; i<n; i++) for (int j=1; j<i; j++) lC(i,j)=p[k++];
        for (int i=0; i<n; i++) cp[i]=p[k++];
    }
    else if (opar.pstyleC==CDelta)
    {
        FMatrix<double> BBT(n+1,n+1), T1;
        BBT(0,0)=cpp*A(0,0)*2.0;
        for (int i=0; i<n/2; i++) BBT(2*i+1,2*i+1)=exp(p[k++])*A(2*i+1,2*i+1)*2.;
        GLEABC iABC;
        iABC.set_A(A); iABC.set_BBT(BBT);
        iABC.get_C(T1); cpp=T1(0,0);
        for (int i=0; i<n; i++) cp[i]=T1(0,i+1);
        for (int i=0; i<n; i++) for (int j=0; j<n;j++) lC(i,j)=T1(i+1,j+1);
    }
    
    C(0,0)=cpp;
    for (int i=0; i<n; i++)  for (int j=0; j<n; j++) C(i+1,j+1)=lC(i,j);
    for (int i=0; i<n; i++) C(0,i+1)=C(i+1,0)=cp[i];
    
    abc.set_A(A); abc.set_C(C);
#if GLE_DEBUG>1
    abc.get_BBT(lA); 
    std::cerr<<" A is: "<<A<<" C is: \n"<<C<<" D is: \n"<<lA
            <<" **        EXIT pars2AC()       ** \n";
#endif

    //*slog<<" IN PARS2AC  C\n"<<C<<"**************************************\n";
}

void GLEFError::AC2pars()
{
    unsigned long n=opar.ns;
    unsigned long k=0, i;
#if GLE_DEBUG>1
    std::cerr<<" **        ENTERING AC2pars()       ** \n"
            <<" A is: "<<A<<" C is: \n"<<C<<"\n";
#endif
    //>>>>>> DISASSEMBLE A <<<<<<<<<<<
    //first, get the eigenvalues and the sim. matrix (in the input, A might well be in non-simple form)
    std::valarray<double> reva(n), ieva(n); reva=0.; ieva=0.;
    
    FMatrix<double>lA(n,n);
    FMatrix<tblapack::complex> Q, Q1; std::valarray<tblapack::complex> a;
    for (i=0; i<n; i++) for (int j=0; j<n; j++) lA(i,j)=A(i+1,j+1);
    
    EigenDecomposition(lA, Q, Q1, a);
    std::cerr<<"INITIAL EIGENVALUES : "<<a<<"\n*********************************************\n";
    FMatrix<tblapack::complex> W(n,n), W1(n,n), t1;
    
    W*=0;  
    for (i=0; i<n-1; i++) 
    {
        if (abs(imag(a[i])/real(a[i]))>1e-10) //this is a complex eval
        { W(i,i)=W(i+1,i+1)=tblapack::complex(0.5,0.5); W(i,i+1)=W(i+1,i)=tblapack::complex(0.5,-0.5); i++; }
        else { W(i,i)=1.; }
    }
    if (i<n) W(n-1,n-1)=1.;
    W1=W; toolbox::map(W1,conj);
    mult(W1,Q1,t1); Q1=t1; mult(Q,W,t1); Q=t1;
    
    FMatrix<double> S(n,n), S1(n,n); 
    for (i=0; i<n; i++) for (int j=0; j<n; j++) 
    {
        if (abs(imag(Q(i,j))/real(Q(i,j)))>1e-12) ERROR("Imaginary component in transform matrix: "<<Q);
        if (abs(imag(Q1(i,j))/real(Q1(i,j)))>1e-12) ERROR("Imaginary component in inverse transform matrix: "<<Q1);
        S(i,j)=real(Q(i,j)); S1(i,j)=real(Q1(i,j)); 
    }
    for (i=0; i<n-1; i+=2) 
    { 
        if (abs(real(a[i])-real(a[i+1]))<abs(imag(a[i])-imag(a[i+1]))) { reva[i]=reva[i+1]=(real(a[i])+real(a[i+1]))*0.5; ieva[i+1]=-(ieva[i]=(imag(a[i])-imag(a[i+1]))*0.5); }
        else { reva[i]=real(a[i]); reva[i+1]=real(a[i+1]); }
    }
    if (i<n) reva[n-1]=real(a[n-1]);
    
    //computes swaps (eigenvalues must come ordered by decreasing modulus)
    std::valarray<int> pp(n); for (i=0; i<n; i++) pp[i]=i;
    int iswp;
    for (i=0; i<n; i++) for (int j=i+1; j<n; ++j)
        if (
            (ieva[pp[j]]*ieva[pp[j]]+reva[pp[j]]*reva[pp[j]])>
            (ieva[pp[i]]*ieva[pp[i]]+reva[pp[i]]*reva[pp[i]])
           ) { iswp=pp[j]; pp[j]=pp[i]; pp[i]=iswp; }
/*
    old real-last ordering
        if ( 
            abs(ieva[pp[j]])>abs(ieva[pp[i]]) || 
            ( (abs(ieva[pp[j]])==abs(ieva[pp[i]])) && abs(reva[pp[j]])>abs(reva[pp[i]]) )
           ) { iswp=pp[j]; pp[j]=pp[i]; pp[i]=iswp; }
*/
    std::valarray<double> ap(n), bap(n); double app;
    app=abs(A(0,0));
    //transform ap and bap according to similarity matrix
    ap=0.; bap=0.;
    for (i=0; i<n; i++) 
    { 
        for (int j=0; j<n; ++j) ap[i]+=A(0,j+1)*S(j,i);
        for (int j=0; j<n; ++j) bap[i]+=A(j+1,0)*S1(i,j);
    }
    
    //performs swaps 
    // removed to see what happens
    std::valarray<double> sw(n);
    sw=ap;  for (i=0; i<n; ++i) ap[i]=sw[pp[i]]; 
    sw=bap; for (i=0; i<n; ++i) bap[i]=sw[pp[i]]; 
    sw=reva; for (i=0; i<n; ++i) reva[i]=sw[pp[i]];
    sw=ieva; for (i=0; i<n; ++i) ieva[i]=sw[pp[i]];  
    
    
    FMatrix<double> TT;
    mult(S1,lA,TT); mult(TT,S,lA);
        
    FMatrix<double> APO, APOT;
    if (opar.pstyleA==ARealOnly)
    {
        double ascale=reva[0];
        p[k++]=log(ascale); p[k++]=log((app>0.?app:1e-100)/ascale);
        
        double aceta=0.; 
        for (int i=0; i<n; i++) aceta+=pow(ap[i]+bap[i],2.)/reva[i]; aceta*=1./(4.*app);
        if (aceta>1.) { std::cerr<<"WARNING: eta>1, truncating!\n"; aceta=1.-1e-10;}
        p[k++]=sqrt(abs(log(aceta)));
        
        p[k++]=log(reva[0]/ascale);  for(int i=1; i<n; ++i) p[k++]=sqrt(abs(log(reva[i]/reva[i-1])));
        std::valarray<double> rep(n), reg(n);
        for(int i=0; i<n; ++i) { rep[i]=bap[i]*ap[i]; }
        reg[0]=app-rep[0]/reva[0]; for(int i=1; i<n; ++i) reg[i]=reg[i-1]-rep[i]/reva[i]; 
        for(int i=0; i<n; ++i) p[k++]=log(reg[i]/ascale);
        for(int i=0; i<n; ++i) p[k++]=ap[i];
    }
    else if (opar.pstyleA==AComplex)
    {
        double ascale=sqrt(pow((reva[0]+reva[1])*0.5,2.)+pow((ieva[0]+ieva[1])*0.5,2.));
        p[k++]=log(ascale); p[k++]=log((app>0.?app:1e-100)/ascale);
        
        double aceta=0.; 
        for (int i=0; i<n; i++) aceta+=pow(ap[i]+bap[i],2.)/reva[i]; aceta*=1./(4.*app);
        if (aceta>1.) { std::cerr<<"WARNING: eta>1, truncating!\n"; aceta=1.-1e-10;}
        p[k++]=sqrt(abs(log(aceta)));
        
        std::valarray<double> rer(n/2), ret(n/2), reg(n/2), rep(n/2), req(n/2), repi(n/2), reti(n/2);
        
        //now, we don't know how are the eigenvalues, but we want something which works if these 
        //are complex, and gives something reasonable if they are mixed real and imag.
        for(int i=0; i<n/2; ++i) rer[i]=sqrt(pow((reva[2*i]+reva[2*i+1])*0.5,2.)+pow((ieva[2*i]-ieva[2*i+1])*0.5,2.)); 
        for(int i=0; i<n/2; ++i) ret[i]=atan2((ieva[2*i]-ieva[2*i+1])*0.5,(reva[2*i]+reva[2*i+1])*0.5); 
        
        p[k++]=-log(rer[0]/ascale); //ascale is equal to |eva[0]|
        for(int i=1; i<n/2; ++i) p[k++]=sqrt(abs(log(rer[i]/rer[i-1])));
        for(int i=0; i<n/2; ++i) p[k++]=ret[i];
        
        for(int i=0; i<n/2; ++i)
        { rep[i]=ap[2*i]*bap[2*i]+ap[2*i+1]*bap[2*i+1]; req[i]=ap[2*i]*bap[2*i+1]-ap[2*i+1]*bap[2*i]; }
        for(int i=0; i<n/2; ++i) { reti[i]=atan2(req[i],rep[i]); }
        for(int i=0; i<n/2; ++i) { reg[i]=(i==0?app:reg[i-1])-(rep[i]*cos(ret[i])-req[i]*sin(ret[i]))/rer[i]; } 
        
        for(int i=0; i<n/2; ++i) p[k++]=log((reg[i]>0.?reg[i]:rer[i])/ascale); //if gamma turns out to be negative, just use rho
        for(int i=0; i<n/2; ++i) p[k++]=reti[i];
        
        for(int i=0; i<n; ++i) p[k++]=ap[i];
    }
    else if (opar.pstyleA==AFull)
    {
        p[k++]=app;
        for (int i=0; i<n; i++) p[k++]=ap[i];
        for (int i=0; i<n; i++) p[k++]=bap[i];
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) p[k++]=lA(i,j);
    }
    else if (opar.pstyleA==APositive)
    {
        double ascale=0.; for(int i=0; i<n+1; ++i) ascale+=A(i,i); ascale*=1./(n+1.);
        p[k++]=log(ascale); p[k++]=log(app/ascale);
        
        FMatrix<double> Q(n+1,n+1), P(n+1,n+1), QQT, AT;
        transpose(A,AT);
        P=A; P-=AT; P*=0.5/ascale;
        QQT=A; QQT+=AT; QQT*=0.5/ascale;
        StabCholesky(QQT,Q);
        
        for(int i=1; i<n+1; ++i) p[k++]=log(Q(i,i)>0?Q(i,i):1e-100);
        for(int i=1; i<n+1; ++i) for(int j=0; j<i; ++j) p[k++]=Q(i,j);
        for(int i=1; i<n+1; ++i) for(int j=0; j<i; ++j) p[k++]=P(i,j);
    }
    else if (opar.pstyleA==ADelta)
    {
        double ascale=1.0; 
        p[k++]=log(ascale); p[k++]=log(app/ascale);
        for (int i=0; i<n/2; i++) p[k++]=log(pow((A(0,2*i+1)-A(2*i+1,0))*0.5,2.)*(2*constant::pi));
        for (int i=0; i<n/2; i++)  { p[k++]=log(A(2*i+1,2*i+1));  p[k++]=log(fabs(A(2*i+1,2*i+2)-A(2*i+2,2*i+1))*0.5); }
    }
    else if (opar.pstyleA==APReal || opar.pstyleA==APGeneral)
    {
        double ascale=0.; for(int i=0; i<n+1; ++i) ascale+=A(i,i); ascale*=1./(n+1.);
        p[k++]=log(ascale); 
        
        FMatrix<double> S(n+1,n+1), P(n+1,n+1), Ss, Os, AT;
        transpose(A,AT);
        P=A; P-=AT; P*=0.5;
        S=A; S+=AT; S*=0.5;
        
        //now, we must diagonalise the small block, and modify A accordingly. 
        Ss.resize(n,n); for(int i=0; i<n; i++) for(int j=0; j<n; j++) Ss(i,j)=S(i+1,j+1); std::valarray<double> sev;
        EigenSolverSym(Ss,Os,sev);
        
        APO.resize(n+1,n+1); APO*=0; APO(0,0)=1.; for(int i=0; i<n; i++) for(int j=0; j<n; j++) APO(i+1,j+1)=Os(i,j);
        transpose(APO,APOT);
        
        mult(APOT,P,AT); mult(AT,APO,P); 
        mult(APOT,S,AT); mult(AT,APO,S); 
        
        P*=1./ascale; S*=1./ascale;
        //OK, now we have the symmetric part with a diagonal block, and the asymmetric one transformed to the same basis
        double qpp;
        qpp=app/ascale;  for(int i=0; i<n; i++) qpp-=S(0,i+1)*S(0,i+1)/S(i+1,i+1); if(qpp<=0) qpp=1e-100;
        p[k++]=log(qpp);
        for(int i=1; i<n+1; ++i) p[k++]=log(S(i,i))*0.5;
        for(int i=1; i<n+1; ++i) p[k++]=S(0,i)/sqrt(S(i,i));
        if (opar.pstyleA==APGeneral)
        {
            for(int i=0; i<n+1; ++i) for(int j=i+1; j<n+1; ++j) p[k++]=P(i,j);
        }
        else for(int i=1; i<n+1; ++i) p[k++]=P(i,0);  //se completely drop the ansymetric Ps block.
    }
    
    //moves on to C
    //now get C, which must be transformed...
    FMatrix<double> NC, T1, LS(n+1,n+1), LST(LS);
    LS*=0; LS(0,0)=1.; for (int i=0; i<n; i++) for (int j=0; j<n; j++) LS(i+1,j+1)=S(i,j);
    transpose(LS,LST);
    mult(LST,C,T1); mult(T1,LS,NC); T1=NC; //and reordered
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) NC(1+pp[i],1+pp[j])=T1(1+i,1+j);
    
    //now can get vectors
    double cpp, mc; std::valarray<double>cp(n);
    cpp=NC(0,0); for (int i=0; i<n; i++) cp[i]=NC(0,i+1);

    //ready to write out C
    if(opar.pstyleC==COne)
    { }
    else if (opar.pstyleC==CIndirect)
    {
        FMatrix<double> T1,T2,B,IA,IC;
        if (opar.pstyleA==APositive || opar.pstyleA==AFull) {IA=A; IC=C; } 
        else if (opar.pstyleA==APReal|| opar.pstyleA==APGeneral)
        { mult(APOT,A,T1); mult(T1,APO,IA); mult(APOT,C,T1); mult(T1,APO,IC); }
        else
        { ERROR("A rotation must be implemented"); }
        
        mult(IA,IC,T1); transpose(T1,T2); T2+=T1;
        T2*=(1./T2(0,0));
        std::cerr<<"NEWW IA "<<IA<<"\n";
        std::cerr<<"NEWW IC "<<IC<<"\n";
        std::cerr<<"NEWW BBT "<<T2<<"\n";
        
        StabCholesky(T2,B); cpp=IC(0,0);
        std::cerr<<"NEWW B "<<B<<"\n";
        p[k++]=log(cpp);
        for (int i=0; i<n+1; i++) p[k++]=log(B(i,i)>0?B(i,i):1e-100);
        for (int i=1; i<n+1; i++) for (int j=0; j<i; j++) p[k++]=B(i,j);
    }
    else if (opar.pstyleC==CBDiagonal)
    {
        FMatrix<double> T1,T2,B,IA,IC;
        if (opar.pstyleA==APositive || opar.pstyleA==AFull) {IA=A; IC=C; } 
        else if (opar.pstyleA==APReal|| opar.pstyleA==APGeneral)
        { mult(APOT,A,T1); mult(T1,APO,IA); mult(APOT,C,T1); mult(T1,APO,IC); }
        else
        { ERROR("A rotation must be implemented"); }
        
        mult(IA,IC,T1); transpose(T1,T2); T2+=T1;
        T2*=(1./T2(0,0));
        std::cerr<<"NEWW IA "<<IA<<"\n";
        std::cerr<<"NEWW IC "<<IC<<"\n";
        std::cerr<<"NEWW BBT "<<T2<<"\n";
        
        StabCholesky(T2,B); cpp=IC(0,0);
        std::cerr<<"NEWW B "<<B<<"\n";
        p[k++]=log(cpp);
        for (int i=0; i<n+1; i++) p[k++]=log(B(i,i)>0?B(i,i):1e-100); //keeps only the eigenvalues
        //for (int i=1; i<n+1; i++) for (int j=0; j<i; j++) p[k++]=B(i,j);
    }
    else if (opar.pstyleC==CDelta)
    {
        FMatrix<double> T1,T2,IA,IC;
        if (opar.pstyleA==APositive || opar.pstyleA==AFull || opar.pstyleA==ADelta ) {IA=A; IC=C; } 
        else if (opar.pstyleA==APReal|| opar.pstyleA==APGeneral)
        { mult(APOT,A,T1); mult(T1,APO,IA); mult(APOT,C,T1); mult(T1,APO,IC); }
        else
        { ERROR("A rotation must be implemented"); }
        mult(IA,IC,T1); transpose(T1,T2); T2+=T1;
        std::cerr<<"TEST ME"<<log(T2(0,0)/(IA(0,0)*2.0))<<"\n";
        p[k++]=log(T2(0,0)/(IA(0,0)*2.0));
        for (int i=0; i<n/2; i++) { p[k++]=log((T2(2*i+1,2*i+1)>0?T2(2*i+1,2*i+1):1e-30)/(IA(2*i+1,2*i+1)*2.));
          std::cerr<<"ii: "<<i<<"," <<T2(2*i+1,2*i+1)<<" :: "<<IA(2*i+1,2*i+1)<<"\n"; }
    }
#if GLE_DEBUG>1
    std::cerr<<" parameters: "<<p
    <<" **        EXIT AC2pars()       ** \n";
#endif
}

void init_pars(const GLEFParOptions& fop, std::valarray<double>& ip)
{
    unsigned long n=fop.ns, rnp=npars(fop), k=0;
    ip.resize(rnp); GLEFFitOptions of;
    GLEFError lerr; lerr.set_ops(of, fop);
    
    FMatrix<double> A(n+1,n+1), C(n+1,n+1);  //very stupid initialization
    for (int i=0; i<n+1; ++i) A(i,i)=C(i,i)=1.0;
    
    /*double wmax=fop.fp[fop.fp.size()-1].x, wratio=fop.fp[0].x/wmax;
    for (int i=0; i<n+1; ++i)
    { 
        A(i,i)=1.*pow(wratio,(i)*1./n);
        if (i==0) A(0,0)=(fop.fixGInf>0?fop.fixGInf/wmax:1.); else
        {
            double p=(A(i-1,i-1)-A(i,i))*A(i,i);
            A(0,i)=sqrt(abs(p));
            A(i,0)=p/A(0,i);
        }
        
        if (fop.fixTZero>0) C(i,i)=fop.fixTZero; else C(i,i)=1.; 
    }
    A*=wmax; */
    lerr.A=A; lerr.C=C; lerr.AC2pars(); ip=lerr.p;
    lerr.pars2AC();
    /*
    double mxev, mmev;
    mxev=mmev=fop.fp[0].x;
    for (int i=1; i<fop.fp.size(); i++) 
    { 
        if (mxev<fop.fp[i].x) mxev=fop.fp[i].x;
        if (mmev>fop.fp[i].x) mmev=fop.fp[i].x;
    }
    
    if (!fop.fNoGamma) ip[k++]=log(mmev);  //first choose a tiny gamma
    for (int i=0; i<n; ++i)
    { ip[k]=(log(mmev)+i*log((mxev+mmev)*0.5/mmev)/n)*0.5; ip[k+n]=1.; ++k; }
    
//    for (int i=0; i<n; ++i)
//    { ip[k]=((log(mmev)+log(mxev))/2.)*0.5; ip[k+n]=1.; ++k; }

    //in any case we are
    if (!fop.fClassical)
    {
        if (!fop.fCLimit) ip[ip.size()-1]=fop.temp; 
    }
    */
}

/*double a_cond(const GLEFFitOptions& fop, const std::valarray<double>& ip)
{
    unsigned long n=fop.ns, nv, k;  //we include also the eigenvalues of P, so as to avoid having huge P an tiny Q!!!
    if (fop.fNoGamma) {k=n*(n-1)/2+(n+1)*n/2; nv=n+(n+1)/2; } 
    else {k=(n+1)*n/2+(n+1)*n/2; nv=n+1+(n+1)/2;}
    double lmax=ip[k], lmin=ip[k++];
    //std::cerr<<exp(ip[k-1])<<" ";
    for (int i=1; i<nv; ++i)
    {
    //    std::cerr<<exp(ip[k])<<" ";
        if (ip[k]>lmax) lmax=ip[k];
        if (ip[k]<lmin) lmin=ip[k];
        k++;
    }
    //std::cerr<<" EVALS: "<<lmax<<" , "<<lmin<<"\n";
    return (exp(lmax-lmin));  //if we don't have NoGamma we might be trying to have a very small eigenvalue corresponding to the border.so we take the second last eigenvalue here
}*/
/*
void resize_pars(const GLEFFitOptions& fop, unsigned long n, std::valarray<double>& ip)
{
    unsigned long nn=fop.ns, rnp=npars(fop), k=0, nk=0;
    std::valarray<double> nip;
    nip.resize(rnp); nip=0.;
    double minp=ip[1];
    if (!fop.fNoGamma) nip[nk++]=ip[k++]; //copy gamma
    for (int i=0; i<nn; ++i)
    {   if (i<n) { nip[nk]=ip[k]; nip[nk+nn]=ip[k+n]; if(nip[nk]<minp)minp=nip[nk]; nk++; k++; }
        else { nip[nk]=minp; nip[nk+nn]=-50.; nk++; }
    }
    nk+=nn; k+=n; //since we copied twice
    
    for (int i=(fop.fNoGamma?1:0); i<nn+1; ++i) 
        for (int j=i+1; j<nn+1; ++j) 
            if (i<n+1 && j<n+1) { std::cerr<<"oo "<<i<<":"<<j<<":"<<ip[k]<<"\n"; nip[nk++]=ip[k++];  } else nk++;
    for (int i=1; i<nn+1; ++i) 
        for (int j=i+1; j<nn+1; ++j) 
            if (i<n+1 && j<n+1) nip[nk++]=ip[k++]; else nk++;
    
    if (!fop.fClassical)
    {
        for (int i=0; i<nn; ++i) if (i<n) { nip[nk++]=ip[k++]; } else nip[nk++]=0.;
        for (int i=0; i<nn; ++i) if (i<n) { nip[nk++]=ip[k++]; } else nip[nk++]=0.;
        for (int i=0; i<n; ++i) for (int j=0; j<i; ++j) {std::cerr<<nk<<":"<<k<<"\n"; nip[nk++]=ip[k++]; }
        if (!fop.fCLimit) nip[nip.size()-1]=ip[ip.size()-1];
    }
    ip.resize(nip.size()); ip=nip; 
}*/


void GLEFError::compute_globs(std::map<GLEFGlobType, double>& lims)
{
    lims[GInf]=A(0,0);
    lims[TZero]=C(0,0);
    FMatrix<double> lA(A.rows()-1,A.rows()-1), iA; 
    for (int i=0; i<A.rows()-1; ++i) for (int j=0; j<A.rows()-1; ++j) lA(i,j)=A(i+1,j+1);
    MatrixInverse(lA,iA);
    
    lims[GZero]=A(0,0); 
    for (int i=0; i<A.rows()-1; ++i) for (int j=0; j<A.rows()-1; ++j)
            lims[GZero]-=A(0,i+1)*A(j+1,0)*iA(i,j);
    
    lims[ARatio]=0.;  //assume A is in simple form
    for (int i=1; i<A.rows(); ++i) lims[ARatio]+=pow((A(0,i)+A(i,0))*0.5,2)/A(i,i);
    lims[ARatio]*=1./A(0,0);
    
    lims[TInf]=C(0,0)*A(0,0);
    for (int i=1; i<A.rows(); ++i) lims[TInf]+=C(0,i)*A(0,i);
    lims[TInf]*=1./A(0,0);
    
    lims[CRatio]=0.;
    for (int i=1; i<A.rows(); ++i) lims[CRatio]+=pow((C(0,i)+C(i,0))*0.5,2)/C(i,i);
    lims[CRatio]*=1./C(0,0);
    
    lims[PQRatio]=0.;
    for (int i=0; i<A.rows()-1; ++i) for (int j=0; j<A.rows()-1; ++j)
            lims[PQRatio]+=A(0,i+1)*C(0,j+1)*iA(i,j);
    lims[PQRatio]=lims[PQRatio]/C(0,0);
    
    //eigenvalues distribution
    std::valarray<tblapack::complex> lae; FMatrix<tblapack::complex> lO, lO1;
    EigenDecomposition(lA, lO, lO1, lae);
    double lac=0, lac2=0; for(int i=0; i<lae.size(); i++) { lac+=log(abs(lae[i])); lac2+=pow(log(abs(lae[i])),2);}
    for(int i=0; i<lae.size(); i++) (*seva) << lae[i]<<" "; (*seva)<<std::endl;
    
    lac*=1./lae.size(); lac2*=1./lae.size(); 
    lims[AEigvCenter]=exp(lac); lims[AEigvSpread]=exp(sqrt(lac2-lac*lac)); 
    
    lims[DeltaSpread]=0.;
    for (int i=1; i<A.rows()-1; i+=2)
        lims[DeltaSpread]+=log(abs(A(i,i)/A(i,i+1)));
    lims[DeltaSpread]=lims[DeltaSpread]/(A.rows()-1)*2;
    
    lims[DeltaWeight]=0.;
    for (int i=1; i<A.rows()-1; i+=2)
        lims[DeltaWeight]+=log(abs(A(0,i)/A(i,i+1)));
    lims[DeltaWeight]=lims[DeltaWeight]/(A.rows()-1)*2;

}

void GLEFError::compute_points(const std::vector<double>& xp, std::vector<std::map<GLEFPointType, double> >& val)
{
    FMatrix<double> BBT;
    abc.get_BBT(BBT);
    
    val.resize(xp.size()); 
    double pq;
    for (int i=0; i<xp.size(); i++)
    {
        val[i].clear();
        harm_check(A,BBT,xp[i],val[i][TauQ2],val[i][TauP2],val[i][TauH],val[i][Cqq],val[i][Cpp],pq,val[i][DwQ],val[i][DwP],val[i][LFP]);
        abc.get_KH(xp[i],val[i][Kw],val[i][Hw]);
        if (opar.deltat>0.) verlet_check(A,C,xp[i],opar.deltat,val[i][CqqDT],val[i][CppDT],pq); else  { val[i][CqqDT]=val[i][Cqq]; val[i][CppDT]=val[i][Cpp]; } //if requested, compute finite-dt corrections
        val[i][HonK]=val[i][Hw]/val[i][Kw];
        val[i][rDwQ]=val[i][DwQ]/xp[i];
        val[i][rDwP]=val[i][DwP]/xp[i];
        val[i][KP2]=1./(xp[i]*val[i][TauP2]);
        val[i][KQ2]=1./(xp[i]*val[i][TauQ2]);
        val[i][KH]=1./(xp[i]*val[i][TauH]);
#ifndef __NOPEAK
        harm_peak(A,BBT,xp[i],0.5,val[i][PI2]);
        harm_peak(A,BBT,xp[i],0.1,val[i][PI10]);
        harm_peak(A,BBT,xp[i],0.01,val[i][PI100]);
#endif
    }
}

double compute_chi(const double& y, const GLEFValue& refv)
{
    double dy;
    switch (refv.metric)
    { 
        case Linear:       dy=y-refv.y; break;
        case Logarithmic:  dy=log(fabs(y))-log(fabs(refv.y)); break;
        case Exponential:  dy=exp(y-refv.y); break;  //doesn't mean much
    }
    
    switch (refv.dir)
    { 
        case Greater: if(dy>0.) return 0.; break;
        case Smaller: if(dy<0.) return 0.; break;
    }
    
    dy=pow(fabs(dy),refv.e); 
    
    return dy;
}

#define _MY_NAN 1e50
void nancheck(double& val)
{
    if (std::isnan(val) || std::isinf(val)) val=_MY_NAN;
}

#define LARGE 1e5
void GLEFError::get_value(double& rv)
{
    double dy, chi_glob=0., chi_points=0.;
    
    (*slog) << " **************************************************************** \n";
    (*slog) << "  GLOBAL FITTED PARAMETERS                                        \n";
    /* first goes after global values */
    std::map<GLEFGlobType,double> gvalues;
    std::map<GLEFGlobType,GLEFValue>::iterator git;
    compute_globs(gvalues);
    for (git=ofit.globs.begin(); git!=ofit.globs.end(); git++)
    {
        //fit for this glob has been requested. compute it (and output log)
        (*slog) << git->first<<" "<<gvalues[git->first]<< " "<< git->second.y;
        dy=compute_chi(gvalues[git->first],git->second);
        dy*=git->second.w;
        (*slog) <<" "<< dy<<std::endl;
        chi_glob+=dy;
    }
    
    std::vector<double> freqs; 
    std::map<GLEFPointType, GLEFValue>::iterator pit;
    std::map<GLEFPointType, double> ptotals, pndata, pexp, pweights; 
    std::map<GLEFPointType, double>::iterator ptit;
    std::vector<std::map<GLEFPointType, double> > pvalues;
    /* then goes for points */
    (*slog) << " ---------------------------------------------------------------- \n";
    (*slog) << "  FREQUENCY-DEPENDENT FIT                                         \n";
    
    //populate an array with all the frequencies, we compute all points at once
    freqs.resize(ofit.points.size()); pvalues.resize(ofit.points.size());
    for(int i=0; i<ofit.points.size(); ++i) freqs[i]=ofit.points[i].x;
    compute_points(freqs,pvalues);
    
    ptotals.clear(); pndata.clear(); pexp.clear();
    for(int i=0; i<ofit.points.size(); ++i)
    {
        (*slog) <<" + frequency: "<<ofit.points[i].x<<"\n";
        for (pit=ofit.points[i].values.begin(); pit!=ofit.points[i].values.end(); pit++)
        {
            //if necessary, initialize a term in ptotals and pexp
            if (ptotals.find(pit->first)==ptotals.end())
            {
                pndata[pit->first]=ptotals[pit->first]=0.; pexp[pit->first]=1.;   pweights[pit->first]=1.;
                if (ofit.pexp.find(pit->first)!=ofit.pexp.end()) pexp[pit->first]=ofit.pexp[pit->first]; 
                if (ofit.pweights.find(pit->first)!=ofit.pweights.end()) pweights[pit->first]=ofit.pweights[pit->first];
            }
            (*slog) << pit->first<<" "<<pvalues[i][pit->first]<< " "<< pit->second.y;
            dy=compute_chi(pvalues[i][pit->first], pit->second);
            (*slog) <<" "<< dy<<std::endl;
            dy=pow(dy,pexp[pit->first]);
            dy*=pit->second.w;
            ptotals[pit->first]+=dy;
            pndata[pit->first]+=pit->second.w;
        }
    }
    
    (*slog) << " ---------------------------------------------------------------- \n";
    (*slog) << "  FREQUENCY-DEPENDENT TOTALS                                      \n";
    for (ptit=ptotals.begin(); ptit!=ptotals.end(); ptit++)
    {
        ptit->second=pow(ptit->second/pndata[ptit->first],1./pexp[ptit->first]);
        (*slog) << " "<<ptit->first<<" "<<ptit->second<<" ("<< (ptit->second*pweights[ptit->first]) <<")\n";
        chi_points+=ptit->second*pweights[ptit->first];
    }
    (*slog) << " ---------------------------------------------------------------- \n";
    (*slog) << "  OVERALL ERROR: " <<chi_points+chi_glob<<"                      \n";
    (*slog) << " ---------------------------------------------------------------- \n";
    
    rv=chi_points+chi_glob;
    /*
    HRTimer hrt; hrt.start();
    
    
    
    FMatrix<double> BBT, RQ; FMatrix<tblapack::complex> CQ;
    std::valarray<double> re; std::valarray<tblapack::complex> ce;
    
    
    double wmx;
    wmx=ops.fp[ops.fp.size()-1].x;
    for (int i=ops.fp.size()-1; i>0 && ops.fp[i].w<0; --i);
    double lwb, ldw;
    lwb=sqrt(ops.fp[0].x*wmx);
    ldw=sqrt(wmx/ops.fp[0].x);
    
    if (ops.pstyleA==ARealOnly)
    {
        double wavg=log(A(1,1)), sldw=pow(ldw,1./ops.ns);
        for (int i=2; i<A.rows(); ++i)
        {
            wavg+=log(A(i,i));
            rv_wb+=pow(abs(log(A(i,i)/A(i-1,i-1)/sldw)),ops.wbExponent);
        }
        wavg=exp(wavg/ops.ns);  //try to center the spectrum
        rv_wb+=ops.ns*pow(abs(log(wavg/lwb)),ops.wbExponent);
        std::cerr<<"avg is "<<wavg<<" opposed to "<<lwb<<"\n";
    }
    else if (ops.pstyleA==AComplex)
    {
        double wavg,sldw=pow(ldw,2./ops.ns);
        for (int i=1; i<(A.rows()-1)/2; ++i)
        {
            double mod1,mod2;
            mod1=sqrt(pow(abs(A(1+2*(i-1),1+2*(i-1))),2.)+pow(abs(A(1+2*(i-1),1+2*(i-1)+1)),2.));
            mod2=sqrt(pow(abs(A(1+2*i,1+2*i)),2.)+pow(abs(A(1+2*i,1+2*i+1)),2.));
            if (i==1) wavg+=log(mod1);
            wavg+=log(mod2);
            rv_wb+=1./pow(abs(log(mod2/mod1/sldw)),ops.wbExponent);
        }
        wavg=exp(wavg/(ops.ns/2));
        std::cerr<<"avg is "<<wavg<<" opposed to "<<lwb<<"\n";
        rv_wb+=ops.ns*pow(abs(log(wavg/lwb)),ops.wbExponent);
        
        //compute contributions to gammas, want each to be sizable wrt the previous one
        double wg=A(0,0), wgd;
        std::cerr<<"gamma contributions: "<<wg<<":: ";
        for (int i=0; i<(A.rows()-1)/2; ++i)
        {
            double tr=A(1+2*i,1+2*i), ti=A(1+2*i,1+2*i+1),
                        ta1=A(0,1+2*i),ta2=A(0,1+2*i+1),
                        tb1=A(1+2*i,0),tb2=A(1+2*i+1,0);
            wgd=(ta2*tb1*ti-ta1*tb2*ti+ta1*tb1*tr+ta2*tb2*tr)/(tr*tr+ti*ti);
            
            double wgx=(1.-exp(-pow(abs(wgd/wg-1),ops.wgExponent+1.)*ops.wgExponent/(ops.wgExponent+1.)));
            std::cerr<<wgd<<"("<<wg<<","<<wgx<<")  ";
            
            rv_wg+=wgx/(ops.ns/2);
            wg=wg-wgd;
        }
        std::cerr<<std::endl;
    }
    else if (ops.pstyleA==APositive || ops.pstyleA==APReal)
    {
        double wavg=log(dce[0]), sldw=pow(ldw,2./ops.ns);
        for (int i=1; i<dce.size(); ++i)
        {
            wavg+=log(dce[i]);
            rv_wb+=pow(abs(log(dce[i]/dce[i-1]/sldw)),ops.wbExponent); //! following avoids complex eva+1./(abs(log(dce[i]/dce[i-1])));
        }
        wavg=exp(wavg/ops.ns);  //try to center the spectrum
        rv_wb+=ops.ns*pow(abs(log(wavg/lwb)),ops.wbExponent);
        std::cerr<<dce<<"\n";
        std::cerr<<"avg is "<<wavg<<" opposed to "<<lwb<<"("<<ldw<<")\n";
    }
    else if (ops.pstyleA==APGeneral)
    {
        double wavg=log(dce[0]),sldw=pow(ldw,2./ops.ns);
        for (int i=1; i<dce.size(); ++i)
        {
            wavg+=log(dce[i]); 
            rv_wb+=pow(abs(log(dce[i]/dce[i-1]/sldw + (abs(imag(ce[i]))/dce[i]+abs(imag(ce[i-1]))/dce[i-1])/sldw )),ops.wbExponent);
            std::cerr<<ce[i]<<" eigv Ap\n";
        }
        wavg=exp(wavg/ops.ns);  //try to center the spectrum
        rv_wb+=ops.ns*pow(abs(log(wavg/lwb)),ops.wbExponent);
        
        std::cerr<<dce<<"\n";
        std::cerr<<"avg is "<<wavg<<" opposed to "<<lwb<<"("<<ldw<<")\n";
        
        FMatrix<double>la(ops.ns,ops.ns);
        std::valarray<tblapack::complex> lce;
        for(int i=0; i<ops.ns;++i) for(int j=0; j<ops.ns;++j) la(i,j)=A(i+1,j+1);
        EigenSolver(la, CQ, CQ, lce);
        
        wavg=0;
        for (int i=1; i<ops.ns; i+=2)
        {
            wavg+=log(lce[i].real()*lce[i-1].real())/2;
            rv_wg+=pow(abs(imag(lce[i])/lce[i].real()-1.),ops.wgExponent)+pow(abs(log(lce[i].real()/lce[i-1].real())),ops.wgExponent);
            std::cerr<<lce[i]<<"  eigv A\n";
        }
        wavg=exp(wavg/ops.ns*2.);
        rv_wg+=ops.ns*pow(abs(log(wavg/lwb)),ops.wgExponent);
        std::cerr<<"g-avg is "<<wavg<<"\n";
        
        
        
    }
    double nn=0., np=0.;
    for (int i=1; i<ops.ns+1; ++i) { nn+=pow(0.5*abs(A(0,i)-A(i,0)),2.); np+=pow(0.5*abs(A(0,i)+A(i,0)),2.); }
    
    //double tskew=0.;;
    //for (int i=1; i<ops.ns+1; ++i) tskew+=pow(abs(log( abs((A(0,i)*A(i,0))/(A(i,i)*A(0,0)))*ops.ns )), ops.wgExponent);
    rv_wb=pow(rv_wb,1./ops.wbExponent);
    
    //v_wg=abs(log(np/nn))+pow(tskew,1./ops.wgExponent);  //we want the pos and neg components to be balanced
    
    //now compute harmonic analysis and evaluate chi2 for response time and fdt
    double tq2, tp2, th, q2, p2, pq, fh, fk, dw, tw=0., tg;
    
    for (int i=0; i<ops.fp.size(); ++i)
    {
        harm_check(A,BBT,ops.fp[i].x,tq2,tp2,th,q2,p2,pq);
        if (ops.fdMode==All || ops.fdMode==HKRatio || ops.rtMode==Friction)
        {
            abc.get_KH(ops.fp[i].x,fk,fh);
        }
        
        //rt contribution
        double rttgt;
        switch(ops.rtMode)
        {
            case Total:
                rttgt=1./th; 
                break;
            case Potential:
                rttgt=1./tq2;
                break;
            case Kinetic:
                rttgt=1./tp2;
                break;
            case Friction:
                rttgt=fk;
                break;
        }
        
        if (ops.rtLogDistance) dw=log(ops.fp[i].th/rttgt); else dw=ops.fp[i].th-rttgt;
        if (dw>0) rv_rt+=fabs(ops.fp[i].w*pow(fabs(dw),ops.rtExponent));
        else if ( ops.fp[i].w<0. ) {rv_cp+=fabs(ops.fp[i].w)*pow(fabs(dw),ops.rtExponent); }
        tw+=fabs(ops.fp[i].w);
        
        switch(ops.fdMode)
        {
            case Momentum:
                tg=p2; break;
            case Position:
                tg=q2; break;
            case Balanced:
                tg=q2; 
                if (ops.fdLogDistance) dw=log(ops.fp[i].fd/tg); else dw=ops.fp[i].fd-tg;
                if (fabs(ops.fp[i].w)>=0.) rv_fd+=fabs(ops.fp[i].w*pow(fabs(dw),ops.fdExponent));
                tg=p2;
                break;
            case Energy:
                tg=q2+p2; break;
            case HKRatio:
                tg=fh/fk; break;
            case All:
                tg=q2; 
                if (ops.fdLogDistance) dw=log(ops.fp[i].fd/tg); else dw=ops.fp[i].fd-tg;
                if (fabs(ops.fp[i].w)>=0.) rv_fd+=fabs(ops.fp[i].w*pow(fabs(dw),ops.fdExponent));
                tg=p2;
                if (ops.fdLogDistance) dw=log(ops.fp[i].fd/tg); else dw=ops.fp[i].fd-tg;
                if (fabs(ops.fp[i].w)>=0.) rv_fd+=fabs(ops.fp[i].w*pow(fabs(dw),ops.fdExponent));
                tg=fh/fk; break;
            case PIMD:
                tg=q2; 
//                if (ops.fdLogDistance) dw=log(ops.temp/tg); else dw=ops.temp-tg;
//                if (fabs(ops.fp[i].w)>=0.) rv_fd+=fabs(ops.fp[i].w*pow(fabs(dw),ops.fdExponent));
                tg=p2; break;
            default:
                ERROR("Fitting mode not implemented yet.");
        }
        if (ops.fdLogDistance) dw=log(ops.fp[i].fd/tg); else dw=ops.fp[i].fd-tg;
        if (fabs(ops.fp[i].w)>=0.) rv_fd+=fabs(ops.fp[i].w*pow(fabs(dw),ops.fdExponent));
    }
    rv_fd=pow(rv_fd/tw,1./ops.fdExponent);
    rv_rt=pow(rv_rt/tw,1./ops.rtExponent);
    rv_cp=pow(rv_cp/tw,1./ops.rtExponent);
    
    nancheck(rv_pos); nancheck(rv_wb); nancheck(rv_rt); nancheck(rv_wg);
    nancheck(rv_res); nancheck(rv_cp); nancheck(rv_fd);
    // combines data and writes log
    (*slog)<<" ----------------------------------------------------------------- \n";
    rv=0.;
    if (rv_pos>0.)
    {
        (*slog) <<"  MIN-KW:  "<<min_kw
                <<"  MIN_AP:  "<<min_evap
                <<"  MIN_C:   "<<min_evc
                <<"  MIN_BBT: "<<min_evb<<"\n";
    }
    if (ops.resWeight>0.)
    {
        (*slog) <<"  gzero: "<<lims["gzero"]
                <<"  ginf: "<<lims["ginf"]
                <<"  tzero: "<<lims["tzero"]
                <<"  tinf: "<<lims["tinf"]
                <<"  aratio: "<<lims["aratio"]
                <<"  cratio: "<<lims["cratio"]
                <<"  qpratio: "<<lims["qpratio"]
                <<"\n";
    }
    (*slog) <<"  POS-DEF: "<<rv_pos<<" ("<<rv_pos*ops.posWeight<<")"
            <<"  BALAN.:  "<<rv_wb<<" ("<<rv_wb*ops.wbWeight<<")"
            <<"  MK/NMK:  "<<rv_wg<<" ("<<rv_wg*ops.wgWeight<<")"
            <<"  RESTR.:  "<<rv_res<<" ("<<rv_res*ops.resWeight<<")"
            <<"  RESP-T:  "<<rv_rt<<" ("<<rv_rt*ops.rtWeight<<")"
            <<"  CP-DEC:  "<<rv_cp<<" ("<<rv_cp*ops.rtWeight<<")"
            <<"  FLUCT:   "<<rv_fd<<" ("<<rv_fd*ops.fdWeight<<")\n";
    rv=(rv_pos*ops.posWeight+rv_res*ops.resWeight+(rv_cp+rv_rt)*ops.rtWeight+rv_fd*ops.fdWeight+rv_wb*ops.wbWeight+rv_wg*ops.wgWeight)/(ops.posWeight+ops.resWeight+ops.rtWeight+ops.fdWeight+ops.wbWeight+ops.wgWeight);
    (*slog) <<"  OVERALL ERROR: "<<rv<<"\n";
    (*slog)<<" ----------------------------------------------------------------- \n";
    
#if GLE_DEBUG>1
    std::cerr<<" ##       OVERALL ERROR COMPUTED: "<<rv<<"\n";
#endif
*/
}
