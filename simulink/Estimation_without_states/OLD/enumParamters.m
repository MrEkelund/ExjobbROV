function [ varargout ] = enumParamters(before_num, after_num , parameter_list,varargin)  
    %Enumerates the paramters
   m = size(parameter_list,1);
   new_cell_list = [];

   for i=1:m
        temp = strcat(parameter_list{i} , before_num, int2str(i), after_num);
        new_cell_list{i} = temp;
       if nargin > 3
           disp(temp)
       end 
   end
end

