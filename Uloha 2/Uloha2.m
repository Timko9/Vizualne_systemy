obr=imread('MoonlightSonata.jpg');
obr=double(rgb2gray(obr));

map=linspace(0,1,255);
map=[map' map' map'];
colormap(map);
%s1=[1 2 1;0 0 0;-1 -2 -1];  
%s2=[1 0 -1;2 0 -2;1 0 -1];
s1=[0 1 0;1 -4 1;0 1 0];
n=0;                        
y=zeros(size(obr));         
v=1;                        
h=1;

for a=2:length(obr(1:end-1,1))
    for b=2:length(obr(1,1:end-1))
        y(a,b)=h*abs(sum(sum(obr(a-1:a+1,b-1:b+1).*s1)));%+v*abs(sum(sum(obr(a-1:a+1,b-1:b+1).*s2)));
        if y(a,b)>0
n=n+1;
        end
    end
end
y=y/max(max(y));
z=sum(sum(y))/n*2.5;
y=y>=z;

image(y*255);
axis off;
