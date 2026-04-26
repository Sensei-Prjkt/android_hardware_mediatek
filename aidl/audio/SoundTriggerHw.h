/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/android/hardware/soundtrigger3/BnSoundTriggerHw.h>
#include <aidl/android/hardware/soundtrigger3/ISoundTriggerHwCallback.h>
#include <aidl/android/hardware/soundtrigger3/ISoundTriggerHwGlobalCallback.h>
#include <aidl/android/media/soundtrigger/ModelParameter.h>
#include <aidl/android/media/soundtrigger/ModelParameterRange.h>
#include <aidl/android/media/soundtrigger/PhraseSoundModel.h>
#include <aidl/android/media/soundtrigger/Properties.h>
#include <aidl/android/media/soundtrigger/RecognitionConfig.h>
#include <aidl/android/media/soundtrigger/SoundModel.h>
#include <android/binder_interface_utils.h>

#include <memory>
#include <optional>

namespace aidl::android::hardware::soundtrigger3 {

using ::aidl::android::media::soundtrigger::ModelParameter;
using ::aidl::android::media::soundtrigger::ModelParameterRange;
using ::aidl::android::media::soundtrigger::PhraseSoundModel;
using ::aidl::android::media::soundtrigger::Properties;
using ::aidl::android::media::soundtrigger::RecognitionConfig;
using ::aidl::android::media::soundtrigger::SoundModel;

class SoundTriggerHw : public BnSoundTriggerHw {
public:
    SoundTriggerHw();
    ~SoundTriggerHw() override;

    ndk::ScopedAStatus getProperties(Properties* _aidl_return) override;

    ndk::ScopedAStatus registerGlobalCallback(
            const std::shared_ptr<ISoundTriggerHwGlobalCallback>& callback) override;

    ndk::ScopedAStatus loadSoundModel(
            const SoundModel& soundModel,
            const std::shared_ptr<ISoundTriggerHwCallback>& callback,
            int32_t* _aidl_return) override;

    ndk::ScopedAStatus loadPhraseSoundModel(
            const PhraseSoundModel& soundModel,
            const std::shared_ptr<ISoundTriggerHwCallback>& callback,
            int32_t* _aidl_return) override;

    ndk::ScopedAStatus unloadSoundModel(int32_t modelHandle) override;

    ndk::ScopedAStatus startRecognition(
            int32_t modelHandle, int32_t deviceHandle, int32_t ioHandle,
            const RecognitionConfig& config) override;

    ndk::ScopedAStatus stopRecognition(int32_t modelHandle) override;

    ndk::ScopedAStatus forceRecognitionEvent(int32_t modelHandle) override;

    ndk::ScopedAStatus queryParameter(
            int32_t modelHandle, ModelParameter modelParam,
            std::optional<ModelParameterRange>* _aidl_return) override;

    ndk::ScopedAStatus getParameter(
            int32_t modelHandle, ModelParameter modelParam,
            int32_t* _aidl_return) override;

    ndk::ScopedAStatus setParameter(
            int32_t modelHandle, ModelParameter modelParam,
            int32_t value) override;

private:
    ndk::ScopedAStatus unsupported() const;

    std::shared_ptr<ISoundTriggerHwGlobalCallback> mGlobalCallback;
};

} // namespace aidl::android::hardware::soundtrigger3