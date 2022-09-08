#!/usr/bin/python
from selenium import webdriver
import pyautogui

driver = webdriver.Chrome('/home/fahim/Apps/chromedriver')

driver.get('http://192.168.0.1')

driver.find_element_by_xpath('//*[@id="userName"]').send_keys('admin')
driver.find_element_by_xpath('//*[@id="pcPassword"]').send_keys('admin')

driver.find_element_by_xpath('//*[@id="loginBtn"]').click()

pyautogui.click(85,552)
pyautogui.click(427,338)
pyautogui.click(499,463)

driver.quit()
