instrhwinfo('Bluetooth','HC-06');
bt = Bluetooth('HC-06', 1); % haven't figure this out yet, but each time you run this script, disconnect from the bluetooth module (ie. unpower bluetooth)
fopen(bt);
while(1)
    fprintf(bt,'s'); % send s to arduino
    value = fscanf(bt, '%s');
    disp(value);
    pause(5);
    fprintf(bt,'k'); % send k to arduino
    value = fscanf(bt, '%s');
    disp(value);
    pause(5);
end
