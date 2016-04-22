function fitPercent = gradeOfFit(validationData,simulatedData)
fit=100*(1-sqrt(sum((validationData-simulatedData).^2))...
/sqrt(sum((validationData-mean(validationData)).^2)))
end
