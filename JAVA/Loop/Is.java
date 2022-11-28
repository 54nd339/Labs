class Is{
    boolean isArm(int n){
        int m=n;
        int s=0;
        while(n>0){
            int r=n%10;
            s+=(r*r*r);
            n/=10;
        }
        if(m==s)
        return true;
        else
        return false;
    }
    boolean isAuto(int n){
        int m=n;
        int c=0;
        while(m!=0){
            m/=10;
            c++;
        }
        int p=n*n;
        int r=p%(int)Math.pow(10,c);
        if(n==r)
        return true;
        else
        return false;
    }
    boolean isBou(int n){
        int m=n,l=9,s=0;boolean b=false,b1=false;
        while(m!=0){
            int r=m%10;
            if(l>=r)
                l=r;
            else
            {b=true;;break;}
            m/=10;
        }
        m=n;
        while(m!=0){
            int r=m%10;
            if(s<=r)
                s=r;
            else
                {b1=true;break;}
            m/=10;
        }
        if(b && b1)
            return true;
        else
            return false;
    }
    boolean isBuzz(int n){
        if(n%10==7 || n%7==0)
        return true;
        else
        return false;
    }
    boolean isDis(int n){
        int m=n,s=0,k=0;
        while(n>0){
            k++;n/=10;
        }n=m;
        while(n>0){
            int r=n%10;
            s+=(int)Math.pow(r,k);
            k--;n/=10;
        }
        if(m==s)
        return true;
        else
        return false;
    }
    boolean isDuc(int n){
        int r=0,c=0;
        for(int i=n;i!=0;i/=10){
            r=i%10;
            if (r==0){
                c=1;break;
            }
        }
        if(c==1)
            return true;
        else
            return false;
    }
    boolean isEvil(int n){
        int c=0;
        while(n!=0){
            int r=n%2;
            if(r==1)
            c++;
            n/=2;
        }
        if(c%2==0)
        return true;
        else
        return false;
    }
    boolean isFasc(int n){
        boolean b=false;char ch=' ';
        for(int i=1;i<=9;i++){
            int m=n*2,o=n*3;
            String s=""+n+m+o;
            b=false;
            for(int j=0;j<s.length();j++){
                ch=s.charAt(j);
                if((int)ch-48==i){
                    b=true;break;}
            }
            if(b==true) continue;
            else break;
        }   
        return b;
    }
    boolean isHap(int n){
        int s=n;
        while(s>9){
            n=s;s=0;
            while(n!=0){
                int r=n%10;
                s=s+r*r;
                n/=10;
            }
        }
        if(s==1)
        return true;
        else
        return false;
    }
    boolean isKap(int n){
        int m=n*n,c=0,i=m;
        while(m!=0){
            m/=10;
            c++;
        }
        if(n%2==0)
        c/=2;
        else
        c=(c+1)/2;
        int r=i%(int)Math.pow(10,c);
        int l=i/(int)Math.pow(10,c);
        if(r+l==n){
        return(true);
        }else{
        return(false);}
    }
    boolean isMagi(int n){
        int s=n;
        while(s>10){
            n=s;s=0;
            while(n>0){
                int r=n%10;
                s+=r;
                n/=10;
            }
        }
        if(s==1)
        return true;
        else
        return false;
    }
    boolean isNeo(int n){
        int m=n*n;
        int s=0;
        while(m!=0){
            int r=m%10;
            s+=r;
            m/=10;
        }
        if(s==n)
        return true;
        else
        return false;
    }
    boolean isNiv(int n){
        int s=0,m=n;
        while(n!=0){
            s+=n%10;
            n/=10;
        }
        if(m%s==0)
            return true;
        else
        return false;
    }
    boolean isPalin(int n){
        int m=n;
        int s=0;
        while(n!=0){
            int r=n%10;
            s=s*10+r;
            n/=10;
        }
        if(s==m)
        return true;
        else
        return false;
    }
    boolean isPer(int n){
        int s=0;
        for(int i=1;i<n;i++){
            if(n%i==0)
            s+=i;
        }
        if(s==n)
        return true;
        else
        return false;
    }
    boolean isPP(int n){
        int s=0;
        Is ob=new Is();
        for(int i=1;i<n;i++){
            if(n%i==0 && (i==1?true:ob.isPrime(i)))
            s+=i;
        }
        if(s==n)
        return true;
        else
        return false;
    }
    boolean isPron(int n){
        boolean b=false;
        for(int i=0;i<=n;i++)
        if(i*(i+1)==n){
        b=true;break;}
        return b;
    }
    int digit(int k){
        int s1=0;
        while(k!=0){
            int r=k%10;
            s1+=r;
            k/=10;
        }
        return s1;
    }
    boolean isRect(int n){
        boolean b=false;
        for(int i=1;i<=n;i++){
            if(i*(i+1)==n){
                b=true;
                break;}   
        }
        return b;
    }
    boolean isSmit(int n){
        Is ob=new Is();
        int s1=ob.digit(n);
        int k=n,s=0;
        if(ob.isPrime(n))
            return false;
        else{
            for(int i=2;i<=k;i++){
                while(k%i==0){
                    k/=i;
                    s+=ob.digit(i);
                }
            }}
        if(s==s1)
            return true;
        else
            return false;
    }
    boolean isSpec(int n){
        int s=0,p=1;
        for(int i=n;i!=0;i/=10){
            int r=n%10;
            for(int j=1;j<=r;j++)
            p*=j;
            s+=p;
            p=1;
        }
        if(s==n)
        return true;
        else
        return false;
    }
    boolean isSp2(int n){
        int s=0,p=1;
        while(n!=0){
            int r=n%10;
            s+=r;p*=r;
            n/=10;
        }
        if(s+p==n)
        return true;
        else
        return false;
    }
    boolean isSP(int n){
        int s=0,p=1;
        while(n!=0){
            int r=n%10;
            s+=r;p*=r;
            n/=10;
        }
        if(s==p)
        return true;
        else
        return false;
    }
    boolean isSp(int n){
        int k=n,c=0;
        for(int i=2;i<=k;i++){
            int c1=0;
            while(k%i==0){
                k/=i;c1++;}
            if(c1==1)
            c++;
        }
        if(c==3)
        return true;
        else
        return false;
    }
    boolean isTri(int n){
        int s=0;boolean b=false;
        for(int i=1;i<=n;i++){
            s+=i;
            if(s==n){
                b=true;
                break;}   
        }
        return b;
    }
    boolean isUniq(int n){
        int m=n,c=0;
        for(int i=0;i<10;i++){
            c=0;
            while(n!=0){
                int r=n%10;
                if(r==i){
                    c++;
                }n=n/10;
            }
            if(c>1)
            break;
            n=m;
        }
        if(c==0||c==1)
        return true;
        else
        return false;
    }
    int fact(int n){
        if(n==0)
        return (1);
        else
        return(n*fact(n-1));
    }
    void pf(int n){
        int k=n;
        System.out.println("Prime Factors of "+n+" are:");
        for(int i=2;i<=k;i++){
            while(k%i==0){
                k/=i;
                System.out.println(i);
            }
        }
    }
    boolean isPrime(int n){
        int c=0;
        for(int i=1;i<=n;i++){
            if(n%i==0)
            c++;
        }
        if(c==2)
        return true;
        else
        return false;
    }
    boolean isTP(int n){
        Is ob=new Is();
        if(ob.isPrime(n)){
            int S=0;
            for(int i=n;i!=0;i/=10){
                int r=i%10;
                S=S*10+r;
            }
            if(ob.isPrime(S))
                return true;
            else
                return false;
        }
        else return false;
    }
    boolean isCP(int n){
        int m=n,c=0;
        Is ob=new Is();boolean b=true;
        while(m!=0){
            c++;m/=10;
        }
        m=n;
        for(int c1=0;c1<c;c1++){
            b=true;
            if(ob.isPrime(m)==false){
                b=false;break;
            }
            int q=(int)(m/Math.pow(10,c-1));
            int r=(int)(m%Math.pow(10,c-1));
            m=r*10+q;
        }
        if(b)
        return true;
        else
        return false;
    }
    int mobVal(int n){
        int c=0;
        if(n==1)
        System.exit(1);
        for(int i=2;i<=n;i++){
            int c1=0;
            while(n%i==0){
                n/=i;
                c1++;
                if(c1==2){
                    c=0;
                    break;
                }
                c++;
            }
            if(c==-1){
                c=0;
                break;
            }
        }
        if(c==0)
        return (0);
        else
        return((int)Math.pow(-1,c));
    }
    void gold(int n){
        Is ob=new Is();
        if(n>4 && n%2==0){
            System.out.println("Prime Pairs are:");
            for(int i=3;i<=n;i++)
            for(int j=i;j<=n;j++)
            if(ob.isPrime(i) && ob.isPrime(j) && i+j==n)
            System.out.println(i+"\t"+j);
        }
    }
}