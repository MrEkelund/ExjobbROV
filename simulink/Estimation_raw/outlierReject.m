function [Innovation_out,H_out,S_out] = outlierReject(Innovation_in,H_in,S_in,Sigma)
j=1;
outlier=0;
for i=1:length(Innovation_in)
    if (Sigma*S_in(i,i)<Innovation_in(i))
        outlier(j)=i;
        j=j+1;
    end
end
if (any(outlier))
    H_in(outlier,:)=[];
    Innovation_in(outlier)=[];
    S_in(outlier,:)=[];
    S_in(:,outlier)=[];
    Innovation_out=Innovation_in;
    H_out=H_in;
    S_out=S_in;
else
    H_out=H_in;
    S_out=S_in;
    Innovation_out=Innovation_in;
end
end