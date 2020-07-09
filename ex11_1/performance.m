test_num = 1000;
perform = zeros(test_num-2,3);
flop = 2;
for i = 2 : test_num
    %create matrix
    E = eye(i);
    E(1,1) = 4;
    E(2,2) = 5;
    E(1,i) = 0.5;
    tic
    U = chol(E);
    myTime = toc;
    perform(i-1,1) = i;
    perform(i-1,2) = myTime;
    flop = flop + 2*i^2;
    if  myTime == 0
        perform(i-1,3) = 0 ;%%too small
    else
        perform(i-1,3) = flop/myTime;%%%Flop
    end
end
 A = readBinary("performance_1000");
 figure;
scatter(perform(:,1),perform(:,3),15,"filled");
hold on;
scatter(A(:,1),A(:,3),15,"filled");