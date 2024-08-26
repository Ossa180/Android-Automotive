# Create Radio - Station Communcation and Disconnect
---

### Init
- Created 2 class ( Radio - Station )
- Radio >> signal
- station >> Slot

### Radio Setup

- make a signal quit()
- make a slot listen(int channel,QString name,QString message)
- implement listen to display channel , name , message

### Station Setup

- create int channel , QString name Attributes
- add channel and name to Constructor
- create signal stationSend (int channel,QString name,QString message)
- create slot broadcast (QString message)
- implement broadcast
    - emit stationSend (channel,name,message)

### instance ( main )
// Check source Code //

---
---
## Resault
- ON
  ![image](https://github.com/user-attachments/assets/07f1ce9a-c63d-4761-adc6-f60e2c21f69a)
  
- TEST
  ![image](https://github.com/user-attachments/assets/8b83f8aa-bdc1-4a18-a2d5-25a0792eab55)

- OFF
  ![image](https://github.com/user-attachments/assets/b4ebeda4-af92-4c48-9ff7-286444152d18)

- QUIT
  ![image](https://github.com/user-attachments/assets/6ba70912-5c84-4daf-9896-17e471dc3353)

