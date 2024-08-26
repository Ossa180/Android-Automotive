# Create Simple Signal and Slot
---
- Create 2 Qobject classes ( Source - Destination)
- in source
    - create function in Signal
    - that function can’t be implemented
- Slot (destination)
    - in .h  create public slots:
    - create a function you want and implement it
- in MAIN
    - include both .h file
    - make object for each
    - connect them together by call QObject::connect
    - `QObject::connect(&oSource,&source::mySignal,&oDestination,&destination::mySlot);`
    - emit signal to test
        - using function  oSource.test();  >> `emit mySignal("hello world");`
        oSource.test();
        - directly oSource→mySignal();
        `emit oSource.mySignal("hi");`

### Notes:

- signal and slots can be in same class
- i can use slot function as a normal function and as a Slot
