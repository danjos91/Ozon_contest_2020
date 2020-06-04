package main

import "sync"

var m sync.Mutex

func Merge2Channels(f func(int) int, in1 <-chan int, in2 <-chan int, out chan<- int, n int) {
	go func() {

		for i := 0; i < n; i++ {
			m.Lock()
			go func() {
				out <- (f(<-in1) + f(<-in2))
				m.Unlock()
			}()
		}
	}()
}
