Thread 1::
void init() {
	mThread = PR_CreateThread(mMain, ...);
}

Thread 2::
void mMain(...) {
	mState = mThread->State;
}
