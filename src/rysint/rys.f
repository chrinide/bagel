c
c Author : Toru Shiozaki
c Date   : May 2009
c
c t (input array): T 
c x (output) : array of root positions 
c w (output) : array of list of weights
c n (input): quadruture rank
c jacobia/b/r/s (input/out) : data for Jacobi; const
c
      subroutine rysroot(ta,x,w,n,bsize)
      implicit none
      integer n,n2,i,k,l,ibatch,bsize,offset
      double precision jacobia(40),jacobib(40), 
     &                 jacobir(100),jacobis(100)
      save jacobia, jacobib, jacobir, jacobis
      data jacobia /
     1  0.333333333333333d0, 0.523809523809524d0, 0.506493506493506d0, 
     2  0.503030303030303d0, 0.501754385964912d0, 0.501144164759725d0, 
     3  0.500805152979066d0, 0.500597371565114d0, 0.500460829493088d0, 
     4  0.500366300366300d0, 0.500298151460942d0, 0.500247402276101d0, 
     5  0.500208594075928d0, 0.500178253119430d0, 0.500154083204931d0,
     1  0.500134517083670d0, 0.500118455342336d0, 0.500105108261509d0, 
     2  0.500093896713615d0, 0.500084388185654d0, 0.500076254384627d0, 
     3  0.500069242487190d0, 0.500063155235569d0, 0.500057836899942d0, 
     4  0.500053163211058d0, 0.500049034029617d0, 0.500045367933944d0, 
     5  0.500042098172939d0, 0.500039169604387d0, 0.500036536353672d0,
     1  0.500034160005466d0, 0.500032008194098d0, 0.500030053495221d0, 
     2  0.500028272547356d0, 0.500026645350386d0, 0.500025154701414d0, 
     3  0.500023785738071d0, 0.500022525566518d0, 0.500021362956633d0, 
     4  0.500020288090891d0 /
      data jacobib /
     1 0.088888888888888892d0, 0.065306122448979598d0, 
     2 0.063572790845518118d0, 0.063066867772750126d0, 
     3 0.062850625014548758d0, 0.062738320280853369d0, 
     4 0.062672532046733828d0, 0.062630684468568856d0, 
     5 0.062602416888131174d0, 0.062582426559912488d0,
     1 0.062567768998403883d0, 0.062556702173852785d0, 
     2 0.062548141713215072d0, 0.062541383866652436d0, 
     3 0.062535955695890350d0, 0.062531529822708584d0, 
     4 0.062527873784375188d0, 0.062524818820395803d0, 
     5 0.062522240012650970d0, 0.062520043292355415d0,
     1 0.062518156728022412d0, 0.062516524554840122d0, 
     2 0.062515103001981112d0, 0.062513857324599020d0, 
     3 0.062512759658762920d0, 0.062511787448488870d0, 
     4 0.062510922276888772d0, 0.062510148986980610d0, 
     5 0.062509455012926249d0, 0.062508829866040130d0,
     1 0.062508264735943064d0, 0.062507752178295059d0, 
     2 0.062507285868274115d0, 0.062506860404442963d0, 
     3 0.062506471151567128d0, 0.062506114113787439d0, 
     4 0.062505785831627553d0, 0.062505483297850939d0, 
     5 0.062505203888325089d0, 0.062504945304910089d0 /
      data jacobir /
     1 0.142857142857142849d0, 0.064935064935064929d0, 
     2 0.042424242424242427d0, 0.031578947368421054d0, 
     3 0.025171624713958809d0, 0.020933977455716585d0, 
     4 0.017921146953405017d0, 0.015668202764976959d0, 
     5 0.013919413919413920d0, 0.012522361359570662d0,
     1 0.011380504700643246d0, 0.010429703796412181d0, 
     2 0.009625668449197862d0, 0.008936825885978428d0, 
     3 0.008340059187516815d0, 0.007818052594171997d0, 
     4 0.007357578305654824d0, 0.006948356807511737d0, 
     5 0.006582278481012658d0, 0.006252859539423517d0,
     1 0.005954853898352029d0, 0.005683971201212581d0, 
     2 0.005436668594563331d0, 0.005209994683678894d0, 
     3 0.005001471020888496d0, 0.004809000998094547d0, 
     4 0.004630799023322388d0, 0.004465334900117509d0, 
     5 0.004311289733284618d0, 0.004167520666803307d0,
     1 0.004033032456308815d0, 0.003906954378794254d0, 
     2 0.003788521345773254d0, 0.003677058353317346d0, 
     3 0.003571967600744579d0, 0.003472717758432044d0, 
     4 0.003378834977699689d0, 0.003289895321512497d0, 
     5 0.003205518360722256d0, 0.003125361731681907d0,
     1 0.003049116490944491d0, 0.002976503134082712d0, 
     2 0.002907268170426065d0, 0.002841181165203511d0, 
     3 0.002778032176328723d0, 0.002717629525729815d0, 
     4 0.002659797855362992d0, 0.002604376426365955d0, 
     5 0.002551217626594511d0, 0.002500185657350793d0,
     1 0.002451155374693606d0, 0.002404011264509925d0, 
     2 0.002358646533671333d0, 0.002314962302219390d0, 
     3 0.002272866883715216d0, 0.002232275142727327d0, 
     4 0.002193107919980167d0, 0.002155291516993645d0, 
     5 0.002118757233152319d0, 0.002083440949084836d0,
     1 0.002049282751037137d0, 0.002016226591609271d0, 
     2 0.001984219982813843d0, 0.001953213717919600d0, 
     3 0.001923161618979110d0, 0.001894020307315476d0, 
     4 0.001865748994568597d0, 0.001838309292183831d0, 
     5 0.001811665037471489d0, 0.001785782134579581d0,
     1 0.001760628408909026d0, 0.001736173473664045d0, 
     2 0.001712388607373755d0, 0.001689246641346862d0, 
     3 0.001666721856132102d0, 0.001644789886154739d0, 
     4 0.001623427631785666d0, 0.001602613178175879d0, 
     5 0.001582325720256755d0, 0.001562545493366461d0,
     1 0.001543253709016199d0, 0.001524432495357410d0, 
     2 0.001506064841953375d0, 0.001488134548496456d0, 
     3 0.001470626177145953d0, 0.001453525008191832d0, 
     4 0.001436816998776653d0, 0.001420488744432406d0, 
     5 0.001404527443210797d0, 0.001388920862205238d0,
     1 0.001373657306280541d0, 0.001358725588842292d0, 
     2 0.001344115004492363d0, 0.001329815303430079d0, 
     3 0.001315816667470394d0, 0.001302109687561142d0, 
     4 0.001288685342691172d0, 0.001275534980090000d0, 
     5 0.001262650296627645d0, 0.001250023321330622d0 /
      data jacobis /
     1  7.50000000000000000d0, 12.25000000000000000d0, 
     2 13.48285714285714221d0, 14.09438775510204067d0, 
     3 14.46430976430976401d0, 14.71312778130960019d0, 
     4 14.89222316145393066d0, 15.02740196078431367d0, 
     5 15.13309658228616605d0, 15.21802532647408057d0,
     1 15.28777123497620316d0, 15.34607750472589771d0, 
     2 15.39554871794871715d0, 15.43805368039084591d0, 
     3 15.47496835564420259d0, 15.50732842209819395d0, 
     4 15.53592842095515891d0, 15.56138812281669459d0, 
     5 15.58419810553523277d0, 15.60475176793188012d0,
     1 15.62336826876898499d0, 15.64030925807561800d0, 
     2 15.65579127693836270d0, 15.66999508042239064d0, 
     3 15.68307273929980106d0, 15.69515311460535756d0, 
     4 15.70634612411045339d0, 15.71674610078916245d0, 
     5 15.72643446106422438d0, 15.73548184288479312d0,
     1 15.74394983262266656d0, 15.75189237019594124d0, 
     2 15.75935690027538527d0, 15.76638532155043393d0, 
     3 15.77301477421555198d0, 15.77927829696035822d0, 
     4 15.78520537801828816d0, 15.79082241968557732d0, 
     5 15.79615313176056191d0, 15.80121886627855154d0,
     1 15.80603890351462404d0, 15.81063069733627202d0, 
     2 15.81501008649131634d0, 15.81919147722465091d0, 
     3 15.82318800166294182d0, 15.82701165563779888d0, 
     4 15.83067341899593750d0, 15.83418336093897238d0, 
     5 15.83755073252211254d0, 15.84078404810177965d0,
     1 15.84389115724256492d0, 15.84687930836248348d0, 
     2 15.84975520520322334d0, 15.85252505705175352d0, 
     3 15.85519462350537090d0, 15.85776925445964025d0, 
     4 15.86025392590357086d0, 15.86265327202619346d0, 
     5 15.86497161407047152d0, 15.86721298631265853d0,
     1 15.86938115949576655d0, 15.87147966200354432d0, 
     2 15.87351179902512222d0, 15.87548066992936313d0, 
     3 15.87738918404101618d0, 15.87924007498762435d0, 
     4 15.88103591376601109d0, 15.88277912065970909d0, 
     5 15.88447197612352113d0, 15.88611663073818114d0,
     1 15.88771511432648076d0, 15.88926934431214555d0, 
     2 15.89078113339385645d0, 15.89225219659895849d0, 
     3 15.89368415777464882d0, 15.89507855556821347d0,
     4 15.89643684894270947d0, 15.89776042226959163d0, 
     5 15.89905059003571353d0, 15.90030860119830791d0,
     1 15.90153564321831148d0, 15.90273284579940416d0, 
     2 15.90390128435750228d0, 15.90504198324313556d0, 
     3 15.90615591873696388d0, 15.90724402183689357d0, 
     4 15.90830718085347151d0, 15.90934624382881069d0, 
     5 15.91036202079285466d0, 15.91135528586962877d0, 
     1 15.91232677924496031d0, 15.91327720900620868d0, 
     2 15.91420725286359428d0, 15.91511755976193498d0, 
     3 15.91600875139083726d0, 15.91688142360072966d0, 
     4 15.91773614773152801d0, 15.91857347186013527d0, 
     5 15.91939392197252090d0, 15.92019800306565536d0 /
      double precision ta(*)
      double precision t
      double precision a(n+n),b(n+n)
      double precision x(*),w(*) 
      double precision lp(n+n)
      double precision sigma0(n+n),sigma1(100)
      double precision invt,invt2,invtt2,sqrtt,invsqrtt,coeff,mone
      double precision sqrtpi2,scal
      parameter (sqrtpi2=0.886226925452758013649083741671d0)
      integer iter,mm,tint,jstart
      double precision bb,c,dd,f,g,p,r,s,td,rinv
      double precision myerf
      logical laguerre,tnonzero,tnothuge,nistwo
      integer thresh(20)
      save thresh
      data thresh /  0, 20, 20, 20, 20, 
     &              20, 20, 20, 20, 20,
     &              20, 21, 22, 23, 23,
     &              23, 23, 23, 23, 23 / ! enough for ang = s p d f... 10
c
c for derf
      integer k_erf
      double precision a_erf, b_erf, y_erf, t_erf
      save a_erf, b_erf
      dimension a_erf(0:64), b_erf(0:64)
      data (a_erf(i), i = 0, 12) / 
     &    0.00000000005958930743d0, -0.00000000113739022964d0, 
     &    0.00000001466005199839d0, -0.00000016350354461960d0, 
     &    0.00000164610044809620d0, -0.00001492559551950604d0, 
     &    0.00012055331122299265d0, -0.00085483269811296660d0, 
     &    0.00522397762482322257d0, -0.02686617064507733420d0, 
     &    0.11283791670954881569d0, -0.37612638903183748117d0, 
     &    1.12837916709551257377d0 / 
      data (a_erf(i), i = 13, 25) / 
     &    0.00000000002372510631d0, -0.00000000045493253732d0, 
     &    0.00000000590362766598d0, -0.00000006642090827576d0, 
     &    0.00000067595634268133d0, -0.00000621188515924000d0, 
     &    0.00005103883009709690d0, -0.00037015410692956173d0, 
     &    0.00233307631218880978d0, -0.01254988477182192210d0, 
     &    0.05657061146827041994d0, -0.21379664776456006580d0, 
     &    0.84270079294971486929d0 / 
      data (a_erf(i), i = 26, 38) / 
     &    0.00000000000949905026d0, -0.00000000018310229805d0, 
     &    0.00000000239463074000d0, -0.00000002721444369609d0, 
     &    0.00000028045522331686d0, -0.00000261830022482897d0, 
     &    0.00002195455056768781d0, -0.00016358986921372656d0, 
     &    0.00107052153564110318d0, -0.00608284718113590151d0, 
     &    0.02986978465246258244d0, -0.13055593046562267625d0, 
     &    0.67493323603965504676d0 / 
      data (a_erf(i), i = 39, 51) / 
     &    0.00000000000382722073d0, -0.00000000007421598602d0, 
     &    0.00000000097930574080d0, -0.00000001126008898854d0, 
     &    0.00000011775134830784d0, -0.00000111992758382650d0, 
     &    0.00000962023443095201d0, -0.00007404402135070773d0, 
     &    0.00050689993654144881d0, -0.00307553051439272889d0, 
     &    0.01668977892553165586d0, -0.08548534594781312114d0, 
     &    0.56909076642393639985d0 / 
      data (a_erf(i), i = 52, 64) / 
     &    0.00000000000155296588d0, -0.00000000003032205868d0, 
     &    0.00000000040424830707d0, -0.00000000471135111493d0, 
     &    0.00000005011915876293d0, -0.00000048722516178974d0, 
     &    0.00000430683284629395d0, -0.00003445026145385764d0, 
     &    0.00024879276133931664d0, -0.00162940941748079288d0, 
     &    0.00988786373932350462d0, -0.05962426839442303805d0, 
     &    0.49766113250947636708d0 / 
      data (b_erf(i), i = 0, 12) / 
     &    -0.00000000029734388465d0, 0.00000000269776334046d0, 
     &    -0.00000000640788827665d0, -0.00000001667820132100d0, 
     &    -0.00000021854388148686d0, 0.00000266246030457984d0, 
     &    0.00001612722157047886d0, -0.00025616361025506629d0, 
     &    0.00015380842432375365d0, 0.00815533022524927908d0, 
     &    -0.01402283663896319337d0, -0.19746892495383021487d0, 
     &    0.71511720328842845913d0 / 
      data (b_erf(i), i = 13, 25) / 
     &    -0.00000000001951073787d0, -0.00000000032302692214d0, 
     &    0.00000000522461866919d0, 0.00000000342940918551d0, 
     &    -0.00000035772874310272d0, 0.00000019999935792654d0, 
     &    0.00002687044575042908d0, -0.00011843240273775776d0, 
     &    -0.00080991728956032271d0, 0.00661062970502241174d0, 
     &    0.00909530922354827295d0, -0.20160072778491013140d0, 
     &    0.51169696718727644908d0 / 
      data (b_erf(i), i = 26, 38) / 
     &    0.00000000003147682272d0, -0.00000000048465972408d0, 
     &    0.00000000063675740242d0, 0.00000003377623323271d0, 
     &    -0.00000015451139637086d0, -0.00000203340624738438d0, 
     &    0.00001947204525295057d0, 0.00002854147231653228d0, 
     &    -0.00101565063152200272d0, 0.00271187003520095655d0, 
     &    0.02328095035422810727d0, -0.16725021123116877197d0, 
     &    0.32490054966649436974d0 / 
      data (b_erf(i), i = 39, 51) / 
     &    0.00000000002319363370d0, -0.00000000006303206648d0, 
     &    -0.00000000264888267434d0, 0.00000002050708040581d0, 
     &    0.00000011371857327578d0, -0.00000211211337219663d0, 
     &    0.00000368797328322935d0, 0.00009823686253424796d0, 
     &    -0.00065860243990455368d0, -0.00075285814895230877d0, 
     &    0.02585434424202960464d0, -0.11637092784486193258d0, 
     &    0.18267336775296612024d0 / 
      data (b_erf(i), i = 52, 64) / 
     &    -0.00000000000367789363d0, 0.00000000020876046746d0, 
     &    -0.00000000193319027226d0, -0.00000000435953392472d0, 
     &    0.00000018006992266137d0, -0.00000078441223763969d0, 
     &    -0.00000675407647949153d0, 0.00008428418334440096d0, 
     &    -0.00017604388937031815d0, -0.00239729611435071610d0, 
     &    0.02064129023876022970d0, -0.06905562880005864105d0, 
     &    0.09084526782065478489d0 / 
c
      nistwo=n.eq.2
      n2=n+n
c
c to activate n == 0 lines, c# must be replaced by spaces
c
      do ibatch=1,bsize !>>>>>>>>>>>> outermost loop >>>>>>>>>>>>>>>>>>>
      t = ta(ibatch)
c
c quick return if not needed
c
      if (t.eq.-1.0d0) cycle 
c
      offset = (ibatch-1)*n 
      tnonzero=(t.gt.1.0d-7)
      tnothuge=(t.lt.60.0d0)
c
      if(tnonzero .and. tnothuge) then 
        sqrtt=dsqrt(t)
        invsqrtt=1.0d0/sqrtt
c
c first calculate derf(sqrtt)
c
        if (sqrtt.lt.2.2d0) then
          t_erf=t 
          k_erf=dint(t_erf)
          t_erf=t_erf-k_erf
          k_erf=k_erf*13
          y_erf=((((((((((((a_erf(k_erf)*t_erf+a_erf(k_erf+1))*t_erf+
     &     a_erf(k_erf+2))*t_erf+a_erf(k_erf+3))*t_erf+
     &     a_erf(k_erf+4))*t_erf+a_erf(k_erf+5))*t_erf+
     &     a_erf(k_erf+6))*t_erf+a_erf(k_erf+7))*t_erf+ 
     &     a_erf(k_erf+8))*t_erf+a_erf(k_erf+9))*t_erf+
     &     a_erf(k_erf+10))*t_erf+a_erf(k_erf+11))*t_erf+
     &     a_erf(k_erf+12))*sqrtt
        else if (sqrtt.lt.6.9d0) then
          k_erf=dint(sqrtt)
          t_erf=sqrtt-k_erf
          k_erf=13*(k_erf-2)
          y_erf=(((((((((((b_erf(k_erf)*t_erf+b_erf(k_erf+1))*t_erf+
     &     b_erf(k_erf+2))*t_erf+b_erf(k_erf+3))*t_erf+
     &     b_erf(k_erf+4))*t_erf+b_erf(k_erf+5))*t_erf+
     &     b_erf(k_erf+6))*t_erf+b_erf(k_erf+7))*t_erf+ 
     &     b_erf(k_erf+8))*t_erf+b_erf(k_erf+9))*t_erf+
     &     b_erf(k_erf+10))*t_erf+b_erf(k_erf+11))*t_erf+b_erf(k_erf+12)
          y_erf=y_erf*y_erf
          y_erf=y_erf*y_erf
          y_erf=y_erf*y_erf
          y_erf=1.0d0-y_erf*y_erf
        else
          y_erf=1.0d0
        end if
        myerf=y_erf
c    
c calculating the modifed moments 
c
        invt    =1.0d0/t
        invt2   =0.5d0*invt
        invtt2  =invt2*invt
        mone=myerf*sqrtpi2*invsqrtt
c
c switch for Laguerre and Jacobi
c
        tint=dint(t) ! cutting off fractions 
        laguerre=tint.ge.thresh(n)
c
        if (laguerre) then 
          coeff=-dexp(-t)*invt2
          sigma1(1)=mone
          lp(1)=1.0d0
c sigma1: modified moments
c a: alphas
c b: betas
          sigma1(2) =coeff*lp(1)
          a(1) =invt2
          b(1) =0.0d0
          lp(2)=1.0d0-1.5d0*invt
c    
          k=n2-2
          do i=2,k
            sigma1(i+1)  =coeff*lp(i)
            a(i)    =dfloat(i*4-3)*invt2
            b(i)    =dfloat((i-1)*(i+i-3))*invtt2
            lp(i+1) =(1.0d0-a(i)-invt2-invt2)*lp(i) 
     &              -(b(i)+dfloat(i+i-2)*invtt2)*lp(i-1)
          enddo
          i=k+1
          sigma1(i+1)=coeff*lp(i)
          a(i)=dfloat(i*4-3)*invt2
          b(i)=dfloat((i-1)*(i+i-3))*invtt2
c
        else ! Jacobi setup 
          a(1) = 0.33333333333333333333333d0
          b(1) = 0.0d0
          do i=2,n2-1
            a(i) =jacobia(i)
            b(i) =jacobib(i-1)
          enddo
          jstart=max(n*5,20)
          sigma1(jstart)=0.0d0
          sigma1(jstart-1)=1.0d-100
          do i=jstart-2,1,-1
            sigma1(i)=
     &       (sigma1(i+2)
     &       -(jacobir(i)+dfloat(i+i+1)*invt2)*sigma1(i+1))
     &       *jacobis(i) 
          enddo
          scal=1.0d0/sigma1(1)
          sigma1(1)=1.0d0
          do i=2,n2
            sigma1(i)=sigma1(i)*scal
          enddo
        endif
c
c entering to Wheeler's algorithm (root search with modified moments)
c
        lp(1)=1.0d0/sigma1(1)
        x(offset+1)=a(1)+sigma1(2)*lp(1)
        w(offset+1)=0.0d0
c
        do k=1,n-1,2
         do l=k,n2-k-1
           sigma0(l+1)=sigma1(l+2)-(x(offset+k)-a(l+1))*sigma1(l+1)
     &                 -w(offset+k)*sigma0(l+1)+b(l+1)*sigma1(l)
         enddo
         lp(k+1)=1.0d0/sigma0(k+1)
         x(offset+k+1)=a(k+1)-sigma1(k+1)*lp(k)+sigma0(k+2)*lp(k+1)
         w(offset+k+1)=sigma0(k+1)*lp(k)
         if(k/=n-1) then
          do l=k+1,n2-k-2
            sigma1(l+1)=sigma0(l+2)-(x(offset+k+1)-a(l+1))*sigma0(l+1)
     &                 -w(offset+k+1)*sigma1(l+1)+b(l+1)*sigma0(l)
          enddo
          lp(k+2)=1.0d0/sigma1(k+2)
          x(offset+k+2)=a(k+2)-sigma0(k+2)*lp(k+1)+sigma1(k+3)*lp(k+2)
          w(offset+k+2)=sigma1(k+2)*lp(k+1)
         endif
        enddo

        do i=2,n
          w(offset+i-1)=w(offset+i)
        enddo
c
c End of Wheelers algorithm
c 
      else if (tnonzero .and. (.not.tnothuge)) then ! t is huge
        sqrtt=dsqrt(t)
        invsqrtt=1.0d0/sqrtt
        mone=sqrtpi2*invsqrtt
        invt=1.0d0/t
        invt2=0.5d0*invt
        invtt2=invt2*invt
        do i=1,n
          x(offset+i)=dfloat(i*4-3)*invt2
          w(offset+i)=dfloat(i*(2*i-1))*invtt2
        enddo

      else ! t is zero 
        if (nistwo) then
          x(offset+1) = 1.15587109997047935d-1
          x(offset+2) = 7.41555747145809208d-1
          w(offset+1) = 6.52145154862546143d-1
          w(offset+2) = 3.47854845137453857d-1
          cycle
        else if (n.eq.3) then
          x(offset+1) = 5.69391159670073532d-2
          x(offset+2) = 4.37197852751093942d-1
          x(offset+3) = 8.69499394918262341d-1
          w(offset+1) = 4.67913934572691047d-1
          w(offset+2) = 3.60761573048138608d-1
          w(offset+3) = 1.71324492379170345d-1
          cycle
        endif
        mone = 1.0d0
        do i=1,n
          x(offset+i)=jacobia(i) 
          w(offset+i)=jacobib(i)
        enddo
      endif ! end of zero
c
c Solving the eigenvalue problem of tridiagonal matrix 
c
c
       lp(1) =1.0d0
       do l=2,2*n
        lp(l) =0.0d0
       enddo
 
       if (nistwo) then
        dd=x(offset+1)+x(offset+2)
        g=x(offset+1)-x(offset+2)
        g=dsqrt(g*g+4.0d0*w(offset+1))
        s=(dd-g)*0.5d0
        c=(dd+g)*0.5d0
        bb=w(offset+1)
        p=(x(offset+1)-s)
        f=(x(offset+1)-c)
        lp(1)=bb/(p*p+bb)
        lp(2)=bb/(f*f+bb)
        x(offset+1)=s
        x(offset+2)=c
        w(offset+1)=lp(1)*mone
        w(offset+2)=lp(2)*mone
       else
        do l=1,n-1
         w(offset+l)=dsqrt(w(offset+l))
        enddo
        w(offset+n)=0.0d0
 
        do l=1,n
         iter=0
  1      do mm=l,n-1
          dd=dabs(x(offset+mm))+dabs(x(offset+mm+1))
          if ((dabs(w(offset+mm))+dd).eq.dd) goto 2
         enddo
         mm=n
  2      if(mm.ne.l) then
          iter=iter+1
          g=(x(offset+l+1)-x(offset+l))/(2.0d0*w(offset+l))
          r=dsqrt(g*g+1.0d0)
          g=x(offset+mm)-x(offset+l)+w(offset+l)/(g+dsign(r,g))
          s=1.0d0
          c=1.0d0
          p=0.0d0
          do i=mm-1,l,-1
           f =s*w(offset+i)
           bb=c*w(offset+i)
           r=dsqrt(f*f+g*g)
           w(offset+i+1)=r
           if(r.eq.0.0d0) then
             x(offset+i+1)=x(offset+i+1)-p
             w(offset+mm)=0.0d0
             goto 1
           endif
           rinv=1.0d0/r
           s=f*rinv
           c=g*rinv
           g=x(offset+i+1)-p
           td=c*bb
           r=(x(offset+i)-g)*s+td+td
           p=s*r
           x(offset+i+1)=g+p     
           g=c*r-bb
           f=lp(i+1) 
           lp(i+1)=s*lp(i)+c*f
           lp(i)  =c*lp(i)-s*f
          enddo
          x(offset+l)=x(offset+l)-p
          w(offset+l)=g
          w(offset+mm)=0.0d0
          goto 1
         endif
        enddo
        do i=1,n
         w(offset+i)=lp(i)*lp(i)*mone
        enddo
       endif
c
      enddo !<<<<<<<<<<<<< outermost loop <<<<<<<<<<<<<<<<<<<
c
c
      return
      end subroutine
c
