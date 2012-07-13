//
//  AudioPlayer.h
//  MobileTheatre
//
//  Created by Matt Donnelly on 27/03/2010.
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MPVolumeView.h>
#import <QuartzCore/QuartzCore.h>
#import "AudioStreamer.h"

@interface MDAudioPlayerController : UIViewController <AVAudioPlayerDelegate, UITableViewDelegate, UITableViewDataSource>
{
  NSMutableArray		*soundFiles;
  NSUInteger			selectedIndex;
  
  AudioStreamer       *audioStreamer;
  
  CAGradientLayer		*gradientLayer;
  
  UIButton			*playButton;
  UIButton			*pauseButton;
  UIButton			*nextButton;
  UIButton			*previousButton;
  UIButton			*toggleButton;
  UIButton			*repeatButton;
  UIButton			*shuffleButton;
  UILabel				*currentTime;
  UILabel				*duration;
  UILabel				*titleLabel;
  UILabel				*artistLabel;
  UILabel				*albumLabel;
  UILabel				*indexLabel;
  UISlider			*volumeSlider;
  UISlider			*progressSlider;
  
  UITableView			*songTableView;
  
  UIButton			*artworkView;
  UIImageView			*reflectionView;
  UIView				*containerView;
  UIView				*overlayView;
  
  NSTimer				*updateTimer;
  
  BOOL				interrupted;
  BOOL				repeatAll;
  BOOL				repeatOne;
  BOOL				shuffle;
}

@property (nonatomic, retain) UIImage *coverImage;
@property (nonatomic, retain) NSMutableArray *soundFiles;

@property (nonatomic, retain) AudioStreamer *audioStreamer;
@property (nonatomic, assign) BOOL currentUserIsPlaying;

@property (nonatomic, retain) CAGradientLayer *gradientLayer;

@property (nonatomic, retain) UIButton *playButton;
@property (nonatomic, retain) UIButton *pauseButton;
@property (nonatomic, retain) UIButton *nextButton;
@property (nonatomic, retain) UIButton *previousButton;
@property (nonatomic, retain) UIButton *toggleButton;
@property (nonatomic, retain) UIButton *repeatButton;
@property (nonatomic, retain) UIButton *shuffleButton;

@property (nonatomic, retain) UILabel *currentTime;
@property (nonatomic, retain) UILabel *duration;
@property (nonatomic, retain) UILabel *indexLabel;;
@property (nonatomic, retain) UILabel *titleLabel;
@property (nonatomic, retain) UILabel *artistLabel;
@property (nonatomic, retain) UILabel *albumLabel;

@property (nonatomic, retain) MPVolumeView *volumeView;
@property (nonatomic, retain) UISlider *progressSlider;

@property (nonatomic, retain) UITableView *songTableView;

@property (nonatomic, retain) UIButton *artworkView;
@property (nonatomic, retain) UIImageView *reflectionView;
@property (nonatomic, retain) UIView *containerView;
@property (nonatomic, retain) UIView *overlayView;

@property (nonatomic, retain) NSTimer *updateTimer;

@property (nonatomic, assign) BOOL interrupted;
@property (nonatomic, assign) BOOL repeatAll;
@property (nonatomic, assign) BOOL repeatOne;
@property (nonatomic, assign) BOOL shuffle;

- (MDAudioPlayerController *)initWithSoundFiles:(NSMutableArray *)songs andSelectedIndex:(int)index;
- (void)dismissAudioPlayer;
- (void)showSongFiles;
- (void)showOverlayView;

- (BOOL)canGoToNextTrack;
- (BOOL)canGoToPreviousTrack;

- (void)stop;
- (void)pause;
- (void)play;
- (void)previous;
- (void)next;
- (void)volumeSliderMoved:(UISlider*)sender;
- (void)progressSliderMoved:(UISlider*)sender;

- (void)toggleShuffle;
- (void)toggleRepeat;

- (void)updateViewForStreamerInfo:(AudioStreamer *)streamer;
- (void)updateViewForStreamerState:(AudioStreamer *)streamer;
- (void)updateTitleViewToCenter;

@end

