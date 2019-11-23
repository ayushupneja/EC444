#  Security

Author: Ayush Upneja, 2019-11-22

## Summary

Identify weaknesses in your node.js to ESP32 system for quest 3 (appliance)

- Small geographical area, need to be connected to router (LAN)
- If a server develops a fault then all users are affected
- It can be difficult to set up the LAN network

What ways can a bad guy attack your specific system? List at least three

- Someone can pretend to be our router in a near physical environment and we connect automatically to their domain 
- Someone can DDOS the router that we are receiving or sending information from
- Someone can just pick up our router and leave


Describe ways that you can overcome these attacks. What ways can you mitigate these issues?
- Have a very specific name and 2 factor authentication
- Cloud flare protection
- Put it in a safe/hidden spot


"IoT" provisioning is a specific challenge for connected devices. Describe how the ESP32 code base provides an IoT provisioning solution. This is the process of associating an ESP32 with a particular user and authentication in a local network.
- We provide an IoT provisioning solution by making a database that logs users identified by a specific ID string.
- Our hub listens for a specific message, to initiate the authentication request.


## Sketches and Photos


## Modules, Tools, Source Used in Solution


## Supporting Artifacts


-----

## Reminders
- Repo is private
